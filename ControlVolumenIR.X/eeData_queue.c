#include "mcc_generated_files/mcc.h"
#include "eeData_queue.h"
#include "eeprom.h"
#include "project.h"


u8 pointerRAM;
u8 queue[EEDATA_SAVE_QUEUE_LENGTH][2];
u8 queueIn;
u8 queueOut;


void eeData_init (void)
{
}

 void eeData_checkEEPROM (void)
{
    u8 aux;

    aux = eeprom_rd(EE_VERSION_ADDR);

    if (aux != FIRMWARE_VERSION)
    {
        eeData_defaults();
    }
    else
    {
        eeData_loadValues();
    }
}

void eeData_loadValues (void)
{
    u8 i;
    
    EE_VERSION = eeprom_rd(EE_VERSION_ADDR);
    
    EEData[EE_WORD_UP_ADDR] = eeprom_rd(EE_WORD_UP_ADDR);
    EEData[EE_WORD_UP_ADDR+1] = eeprom_rd(EE_WORD_UP_ADDR+1);
    EEData[EE_WORD_UP_ADDR+2] = eeprom_rd(EE_WORD_UP_ADDR+2);
    EEData[EE_WORD_UP_ADDR+3] = eeprom_rd(EE_WORD_UP_ADDR+3);
    
    EEData[EE_WORD_DOWN_ADDR] = eeprom_rd(EE_WORD_DOWN_ADDR); 
    EEData[EE_WORD_DOWN_ADDR+1] = eeprom_rd(EE_WORD_DOWN_ADDR+1); 
    EEData[EE_WORD_DOWN_ADDR+2] = eeprom_rd(EE_WORD_DOWN_ADDR+2); 
    EEData[EE_WORD_DOWN_ADDR+3] = eeprom_rd(EE_WORD_DOWN_ADDR+3); 
}

void eeData_defaults (void)
{
    u8 i;

    EE_VERSION = FIRMWARE_VERSION;
    
    EEData[EE_WORD_UP_ADDR] = 0x0F;
    EEData[EE_WORD_UP_ADDR+1] = 0x0F;
    EEData[EE_WORD_UP_ADDR+2] = 0x0F;
    EEData[EE_WORD_UP_ADDR+3] = 0x0F;
    
    EEData[EE_WORD_DOWN_ADDR] = 0x0F;
    EEData[EE_WORD_DOWN_ADDR+1] = 0x0F;
    EEData[EE_WORD_DOWN_ADDR+2] = 0x0F;
    EEData[EE_WORD_DOWN_ADDR+3] = 0x0F;

    eeData_enqueueSave(EE_VERSION_ADDR, 9);
}


void eeData_enqueueSave (u8 address, u8 cant)
{
    queue[queueIn][0] = address;
    queue[queueIn][1] = cant;

    queueIn ++;
    if (queueIn >= EEDATA_SAVE_QUEUE_LENGTH)
        queueIn = 0;
}


void eeData_saveRAM (void)
{
    u8 i;
    u8 addr;
    u8 guarde = 0;


    for (; queueIn != queueOut; queueOut ++)
    {
        guarde = 1;

        INTERRUPT_GlobalInterruptDisable();

        if (queueOut >= EEDATA_SAVE_QUEUE_LENGTH)
            queueOut = 0;

        if (queueIn != queueOut)
        {
            addr = queue[queueOut][0];

            for (i = 0; i < queue[queueOut][1]; i++)
            {
                 eeprom_wr(addr + i, EEData[addr + i], 1);
            }
        }
        else
        {
            break;
        }
    }

    if (guarde == 1)
    {
        INTERRUPT_GlobalInterruptEnable();
    }
}
