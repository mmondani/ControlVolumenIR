#include "samsungIrDecoder.h"
#include "mcc_generated_files/mcc.h"

/*******************************************************************/
// Definiciones
/*******************************************************************/
#define MSEG    (u8)20

/*******************************************************************/
// Variables privadas
/*******************************************************************/
static u8 t_high, t_low;    // Tiempo que la señal está en alto o en bajo
                            // Medido en cantidad de interrupciones de 50us
static u32 irWordAux;       // Palabra IR que estoy recibiendo
static u32 irWord;          // Última palabra IR que recibí

typedef union {
   uint8_t byte;
   struct {
        uint8_t bit0:1;
        uint8_t bit1:1;
        uint8_t bit2:1;
        uint8_t bit3:1;
        uint8_t bit4:1;
        uint8_t lbitent:1;
        uint8_t bitent:1;
        uint8_t bit7:1;
   } bits;
}_regent;
static _regent regent;

static u8 receivingIr;             // Estoy recibiendo una palabra IR
static u8 receivedIr;              // Terminé de recibir una palabra IR
static u8 nBits;                   // Cantidad de bits recibidos de la palabra IR



/*******************************************************************/
// Funciones públicas
/*******************************************************************/
void samsungIrDecorder_init(void)
{
    t_high = 0;
    t_low = 0;
    
    irWord = 0;
    receivedIr = 0;
    receivingIr = 0;
}


void samsungIrDecoder_handler(void)
{
    regent.byte = regent.byte >> 1;
    bit_clear(regent.byte, 7);
    
    (IR_OUT_GetValue())? (regent.bits.bit7 = 1) : (regent.bits.bit7 = 0);
    
    
    // Corregir la entrada
    if ( (regent.byte & 0b11100000) == 0b10100000)
        regent.bits.bitent = 1;
    else if ( ( regent.byte & 0b11100000 ) == 0b01000000)
        regent.bits.bitent = 0;
    
    
    if (regent.bits.bitent == 1)
    {
        if (t_high < 255)
            t_high ++;
    }
    else
        t_low ++;
    
    
    if (receivingIr == 0)
    {
        if (regent.bits.bitent == 0)
        {
            if (t_high > (u8)(40*MSEG)) 
            {
                receivingIr = 1;
                nBits = 0;
                t_low = 0;
                irWordAux = 0;
            }
            
            t_high = 0;
        }
    }
    else
    {
        if (t_high < (u8)(40*MSEG)) 
        {
            // Busco un flanco negativo para determinar que terminó un bit
            if (regent.bits.bitent == 0 && regent.bits.lbitent == 1)
            {
                // El bit de start no se cuenta
                if (nBits > 0)
                {
                    irWordAux = irWordAux << 1;
                
                    /*
                     * Un 1 lógico: 0,6ms bajo (12 cuentas de 50us)
                     *              1,7ms alto (34 cuentas)
                     * 
                     * Un 0 lógico: 0,6ms bajo (12 cuentas)
                     *              0,6ms alto (12 cuentas)
                     * 
                     * Si t_low y t_high difieren en más de 15 cuentas supongo que es un '1'
                    */ 
                    if (t_high > t_low)
                    {
                        if (t_high - t_low > 15)
                            bit_set(irWordAux, 0);
                        else
                            bit_clear(irWordAux, 0);
                    }   
                    else
                        bit_clear(irWordAux, 0);
                    
                }
                
                nBits ++;
                t_high = 0;
                t_low = 0;
                
                // La palabra tiene un bit de start, 32 bits de datos 
                if (nBits > 50)
                {
                    receivingIr = 0;
                }
            }
        }
        else
        {
            if (nBits == 33)
            {
                receivedIr = 1;              
                irWord = irWordAux;
            }
            
            receivingIr = 0;  
        }
    }
}


u8 samsungIrDecoder_hasReceived(void)
{
    return (receivedIr == 1);
}


u32 samsungIrDecoder_getReceivedWord(void)
{
    return irWord;
}