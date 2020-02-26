#ifndef HEADER_V1P0_H
#define	HEADER_V1P0_H

// incluye los typedef
#include <stdint.h>

/******************  Manejo de bit  *********************/
#define bit_test(var, bit) ((var) & (1 <<(bit)))
#define bit_set(var, bit) ((var) |= (1 << (bit)))
#define bit_clear(var, bit) ((var) &= ~(1 << (bit)))
#define nibble_swap(var) (( var >> 4 ) | ( var << 4 ))
#define input(port, bit) ((port &  (1 << bit))? 1 : 0)
#define output_high(port, bit) bit_set(port, bit)
#define output_low(port, bit) bit_clear(port, bit)
#define output_toggle(port, bit) (input(port, bit)? bit_clear(port, bit) : bit_set(port,bit))

/******************  Definitions  *********************/
// Variables
#define         u8                          uint8_t
#define         i8                          int8_t
#define         u16                         uint16_t
#define         i16                         int16_t
#define         u32                         uint32_t
#define         i32                         int32_t


// Macros
#define         _inch128(reg)               ( (reg == 128) ? reg : reg++ )
#define         _inch64(reg)                ( (reg == 64) ? reg : reg++ )
#define         _inch32(reg)                ( (reg == 32) ? reg : reg++ )
#define         _inch16(reg)                ( (reg == 16) ? reg : reg++ )
#define         _inch8(reg)                 ( (reg == 8) ? reg : reg++ )
#define         _inch4(reg)                 ( (reg == 4) ? reg : reg++ )
#define         _dech0(reg)                 ( (reg == 0) ? reg : reg-- )


/**************** Prototipos ****************/




#endif	/* HEADER_V1P0_H */

