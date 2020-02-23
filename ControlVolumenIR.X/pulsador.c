#include "pulsador.h"
#include "temporizadores.h"
#include "mcc_generated_files/mcc.h"


/*******************************************************************/
// Variables privadas
/*******************************************************************/
static gpio_t pulsador;
static Temporizador timerPulsador;
static u8 number, numberAux;
static u8 pressed;

/*******************************************************************/
// Funciones públicas
/*******************************************************************/
void pulsador_init (u8* port, u8 pin)
{
    debounce_Init(&pulsador, GPIO_BAJO_ACTIVO, port, pin);
    timer_Init(&timerPulsador, 500);
    
    number = 0;
    numberAux = 0;
}


void pulsador_handler (void)
{
    debounce_Handler(&pulsador);
    
    if (debounce_getFlanco(&pulsador) == GPIO_FLANCO_A_ACTIVO) 
    {
        timer_Restart(&timerPulsador);
        
        numberAux ++;
    }
    
    
    if (timer_Expiro(&timerPulsador)) 
    {
        if (numberAux > 0) 
        {
           pressed = 1; 
           number = numberAux;
        }
        
        numberAux = 0;
    }
}


u8 pulsador_isPressed (void)
{
    return (pressed == 1);
}


void pulsador_clearPressed (void)
{
    pressed = 0;
}


u8 pulsador_getNumber (void)
{
    return number;
}
