#include "digitalVolumeControl.h"
#include "mcc_generated_files/mcc.h"
#include "basic_definitions.h"



void digitalVolumeControl_init(void)
{
    POT1_CS_SetHigh();
    NOP();
    NOP();
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT1_UD_SetHigh();
    NOP();
    NOP();
    
    
    POT2_CS_SetHigh();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
    POT2_UD_SetHigh();
    NOP();
    NOP();
}


void digitalVolumeControl_activeState(void)
{
    POT1_CS_SetLow();
    NOP();
    NOP();
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT1_UD_SetHigh();
    NOP();
    NOP();
    
    
    POT2_CS_SetLow();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
    POT2_UD_SetHigh();
    NOP();
    NOP();
}


void digitalVolumeControl_storeValue(void)
{
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT1_UD_SetHigh();
    NOP();
    NOP();

    POT2_INC_SetHigh();
    NOP();
    NOP();
    POT2_UD_SetHigh();
    NOP();
    NOP();
    
    
    DELAY_microseconds(100);
    
    POT2_CS_SetHigh();
    NOP();
    NOP();
    POT1_CS_SetHigh();
    NOP();
    NOP();
}


void digitalVolumeControl_up(void)
{
    POT1_CS_SetLow();
    NOP();
    NOP();
    POT1_UD_SetHigh();
    NOP();
    NOP();
    POT2_CS_SetLow();
    NOP();
    NOP();
    POT2_UD_SetHigh();
    NOP();
    NOP();
    
    
    DELAY_microseconds(100);
    
    
    POT1_INC_SetLow();
    NOP();
    NOP();
    POT2_INC_SetLow();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetLow();
    NOP();
    NOP();
    POT2_INC_SetLow();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
}


void digitalVolumeControl_down(void)
{
    POT1_CS_SetLow();
    NOP();
    NOP();
    POT1_UD_SetLow();
    NOP();
    NOP();
    POT2_CS_SetLow();
    NOP();
    NOP();
    POT2_UD_SetLow();
    NOP();
    NOP();
    
    DELAY_microseconds(100);
    
    POT1_INC_SetLow();
    NOP();
    NOP();
    POT2_INC_SetLow();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetLow();
    NOP();
    NOP();
    POT2_INC_SetLow();
    NOP();
    NOP();
    
    DELAY_milliseconds(1);
    
    POT1_INC_SetHigh();
    NOP();
    NOP();
    POT2_INC_SetHigh();
    NOP();
    NOP();
}