#include "mcc_generated_files/mcc.h"
#include "basic_definitions.h"
#include "samsungIrDecoder.h"


/*******************************************************************/
// Prototipos
/*******************************************************************/
void tmr0_isr (void);

/*******************************************************************/
// Variables privadas
/*******************************************************************/
static u32 cuentasIsr;



/*******************************************************************/
// Funciones privadas
/*******************************************************************/
void main(void)
{
    u32 irWord;
    
    
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(tmr0_isr);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    
    while (1)
    {
        if (samsungIrDecoder_hasReceived())
        {
            samsungIrDecoder_clearReceived();
            irWord = samsungIrDecoder_getReceivedWord();
            
            if (irWord == 0)
                LED_ROJO_SetHigh();
        }
    }
}



void tmr0_isr (void)
{
    LED_ROJO_SetHigh(); 
    cuentasIsr ++;
    
    samsungIrDecoder_handler();
    
    
    LED_ROJO_SetLow();    
}