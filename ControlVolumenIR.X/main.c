#include "mcc_generated_files/mcc.h"
#include "basic_definitions.h"

void tmr0_isr (void);


u32 cuentasIsr;


void main(void)
{
    SYSTEM_Initialize();
    
    TMR0_SetInterruptHandler(tmr0_isr);
    
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    
    while (1)
    {
    }
}



void tmr0_isr (void)
{
    LED_ROJO_SetHigh(); 
    cuentasIsr ++;
    LED_ROJO_SetLow();    
}