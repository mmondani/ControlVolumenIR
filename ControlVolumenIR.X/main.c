#include "mcc_generated_files/mcc.h"
#include "basic_definitions.h"
#include "samsungIrDecoder.h"
#include "eeData_queue.h"
#include "debounce.h";
#include "temporizadores.h"
#include "pulsador.h"
#include "digitalVolumeControl.h"


/*******************************************************************/
// Prototipos
/*******************************************************************/
void tmr0_isr (void);


/*******************************************************************/
// Variables privadas
/*******************************************************************/
static u8 t50us, t1ms, t4ms;
static u32 irWord;
static Temporizador timerNewWord;           // Tiempo entre teclas

typedef union {
   uint8_t bytes;
   struct {
        uint8_t bit0:1;
        uint8_t bit1:1;
        uint8_t bit2:1;
        uint8_t bit3:1;
        uint8_t seg1:1;
        uint8_t mseg4:1;
        uint8_t mseg1:1;
        uint8_t bit7:1;
   } bits;
} _timers1;
_timers1 timers1;

typedef union {
   uint8_t byte;
   struct {
        uint8_t event_pulsador:1;
        uint8_t event_newWord:1;
        uint8_t bit2:1;
        uint8_t bit3:1;
        uint8_t bit4:1;
        uint8_t bit5:1;
        uint8_t bit6:1;
        uint8_t bit7:1;
   } bits;
} _events1;
static _events1 events1;


/*******************************************************************/
// FSM Principal
/*******************************************************************/
void fsmControlVolumenIr_init (void);
void fsmControlVolumenIr_handler (void);
void fsmControlVolumenIr_cambio (u8 nextState); 

enum {
    CONTROL_VOLUMEN_IR_INIT = 0,
    CONTROL_VOLUMEN_IR_IDLE,
    CONTROL_VOLUMEN_IR_RECIBIO,
    CONTROL_VOLUMEN_IR_APRENDER,
    CONTROL_VOLUMEN_IR_APRENDIO
};
static u8 fsmControlVolumenIr_state = CONTROL_VOLUMEN_IR_INIT;
static u8 fsmControlVolumenIr_previousState = CONTROL_VOLUMEN_IR_INIT;
static u8 stateIn, stateOut;
static Temporizador timerState;
static Temporizador timerLed;
static u8 nAprendidos;


/*******************************************************************/
// Funciones privadas
/*******************************************************************/
void main(void)
{ 
    
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(tmr0_isr);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    digitalVolumeControl_init();
    digitalVolumeControl_activeState();
    
    eeData_init();
    eeData_checkEEPROM();
    
    pulsador_init(&PORTC, 0);
    
    // 500ms entre tecla y tecla
    timer_Init(&timerNewWord, 500);
    
    
    while (1)
    {
        if (samsungIrDecoder_hasReceived())
        {
            samsungIrDecoder_clearReceived();
            irWord = samsungIrDecoder_getReceivedWord();
            
            if (timer_Expiro(&timerNewWord)) 
            {
                timer_Restart(&timerNewWord);
                events1.bits.event_newWord = 1;
            }
        }
        
        
        if (timers1.bits.mseg4 == 1) 
        {
            /*****************************************/
            // CADA 4ms
            /*****************************************/
            timers1.bits.mseg4 = 0;
            
            pulsador_handler();
            
            fsmControlVolumenIr_handler();
            

            events1.byte = 0;
        }
    }
}



void tmr0_isr (void)
{
    /*****************************************/
    // CADA 50us
    /*****************************************/
    
    //LED_ROJO_SetHigh(); 
    
    samsungIrDecoder_handler();
    
    t50us ++;
    if (t50us >= 20) 
    {
        /*****************************************/
        // CADA 1ms
        /*****************************************/
        timers1.bits.mseg1 = 1;
        
        t50us = 0;
        t1ms ++;
        
        timer_Handler();
        
        if (t1ms >= 4)
        {
            /*****************************************/
            // CADA 4ms
            /*****************************************/
            timers1.bits.mseg4 = 1;
            
            t1ms = 0;
            t4ms ++;
            
            if (t4ms >= 250)
            {
                /*****************************************/
                // CADA 1s
                /*****************************************/
                timers1.bits.seg1 = 1;
                
                t4ms = 0;
            }
        }
    }
    
    
    //LED_ROJO_SetLow();    
}


void fsmControlVolumenIr_init (void)
{
    stateIn = 1;
    stateOut = 0;
}


void fsmControlVolumenIr_handler (void)
{
    u8 nPulsos;
    u32 word0, word1, word2, word3;
    u32 wordUp;
    u32 wordDown;
    
    
    switch (fsmControlVolumenIr_state)
    {
        case CONTROL_VOLUMEN_IR_INIT:
            if (stateIn)
            {
                stateIn = 0;
            }
            /**************************************************************/
            fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_IDLE);
            /**************************************************************/
            if (stateOut)
            {
                stateOut = 0;
                stateIn = 1;
            }
            
            break;
            
        
        case CONTROL_VOLUMEN_IR_IDLE:
            if (stateIn)
            {
                stateIn = 0;
            }
            /**************************************************************/
            if (pulsador_isPressed())
            {
                pulsador_clearPressed();
                        
                nPulsos = pulsador_getNumber();
                
                if (nPulsos == 4)
                {
                    nAprendidos = 0;
                    fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_APRENDER);
                }
            }
            else
            {
                if (events1.bits.event_newWord)
                {
                    word0 = EEData[EE_WORD_UP_ADDR];
                    word1 = EEData[EE_WORD_UP_ADDR+1];
                    word2 = EEData[EE_WORD_UP_ADDR+2];
                    word3 = EEData[EE_WORD_UP_ADDR+3];
                    
                    wordUp = ((word0 << 24) ) |
                            ((word1 << 16) & 0x00ff0000) |
                            ((word2 << 8) & 0x0000ff00) |
                            ((word3 << 0) & 0x000000ff);

                    word0 = EEData[EE_WORD_DOWN_ADDR];
                    word1 = EEData[EE_WORD_DOWN_ADDR+1];
                    word2 = EEData[EE_WORD_DOWN_ADDR+2];
                    word3 = EEData[EE_WORD_DOWN_ADDR+3];
                    
                    wordDown = ((word0 << 24) & 0xff000000) |
                            ((word1 << 16) & 0x00ff0000) |
                            ((word2 << 8) & 0x0000ff00) |
                            ((word3 << 0) & 0x000000ff);
                    
                    if (irWord == wordUp)
                    {
                        //digitalVolumeControl_up();
                        fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_RECIBIO);
                    }
                    else if (irWord == wordDown)
                    {
                        //digitalVolumeControl_down();
                        fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_RECIBIO);
                    }
                }
            }
            
            eeData_saveRAM();
            
            
            /**************************************************************/
            if (stateOut)
            {
                stateOut = 0;
                stateIn = 1;
            }
            
            break;
            
            
        case CONTROL_VOLUMEN_IR_RECIBIO:
            if (stateIn)
            {
                stateIn = 0;
                
                timer_Init(&timerState, 400);
                timer_Init(&timerLed, 50);
            }
            /**************************************************************/
            
            if (timer_Expiro(&timerState))
                fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_IDLE);
            else if (timer_Expiro(&timerLed))
            {
                timer_Restart(&timerLed);
                LED_ROJO_Toggle();
            }
            
            /**************************************************************/
            if (stateOut)
            {
                stateOut = 0;
                stateIn = 1;
                
                LED_ROJO_SetLow();
            }
            
            break;
            
            
        case CONTROL_VOLUMEN_IR_APRENDER:
            if (stateIn)
            {
                stateIn = 0;
                
                timer_Init(&timerState, 5000);
                timer_Init(&timerLed, 200);
            }
            /**************************************************************/
            if (timer_Expiro(&timerState))
                fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_IDLE);
            else if (nAprendidos >= 2)
                fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_IDLE);
            else
            {
                if (timer_Expiro(&timerLed))
                {
                    timer_Restart(&timerLed);
                    LED_ROJO_Toggle();
                }
                
                if (events1.bits.event_newWord) 
                {
                    if (nAprendidos == 0)
                    {
                        EEData[EE_WORD_UP_ADDR] = (irWord >> 24) & 0xff;
                        EEData[EE_WORD_UP_ADDR + 1] = (irWord >> 16) & 0xff;
                        EEData[EE_WORD_UP_ADDR + 2] = (irWord >> 8) & 0xff;
                        EEData[EE_WORD_UP_ADDR + 3] = (irWord >> 0) & 0xff;
                        
                        eeData_enqueueSave(EE_WORD_UP_ADDR, 4);
                    }
                    else
                    {
                        EEData[EE_WORD_DOWN_ADDR] = (irWord >> 24) & 0xff;
                        EEData[EE_WORD_DOWN_ADDR + 1] = (irWord >> 16) & 0xff;
                        EEData[EE_WORD_DOWN_ADDR + 2] = (irWord >> 8) & 0xff;
                        EEData[EE_WORD_DOWN_ADDR + 3] = (irWord >> 0) & 0xff;
                        
                        eeData_enqueueSave(EE_WORD_DOWN_ADDR, 4);
                    }
                      
                    fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_APRENDIO);
                }
            }
            
            /**************************************************************/
            if (stateOut)
            {
                stateOut = 0;
                stateIn = 1;
                
                LED_ROJO_SetLow();
            }
            
            break;
            
            
        case CONTROL_VOLUMEN_IR_APRENDIO:
            if (stateIn)
            {
                stateIn = 0;
                
                timer_Init(&timerState, 2000);
                
                LED_ROJO_SetHigh();
            }
            /**************************************************************/
            if (timer_Expiro(&timerState))
                fsmControlVolumenIr_cambio (CONTROL_VOLUMEN_IR_APRENDER);
                
            /**************************************************************/
            if (stateOut)
            {
                stateOut = 0;
                stateIn = 1;
                
                nAprendidos ++;
                LED_ROJO_SetLow();
            }
            
            break;
    }
}


void fsmControlVolumenIr_cambio (u8 nextState)
{
    fsmControlVolumenIr_previousState = fsmControlVolumenIr_state;
    fsmControlVolumenIr_state = nextState;
    
    stateIn = 0;
    stateOut = 1;
}