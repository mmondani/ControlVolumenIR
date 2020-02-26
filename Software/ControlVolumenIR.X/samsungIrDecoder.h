#ifndef SAMSUNG_IR_DECODER_H
#define	SAMSUNG_IR_DECODER_H

#include <xc.h>
#include "basic_definitions.h"



/*******************************************************************/
// Funciones públicas
/*******************************************************************/
void samsungIrDecorder_init(void);

// Llamarla cada 50us
void samsungIrDecoder_handler(void);

u8 samsungIrDecoder_hasReceived(void);
void samsungIrDecoder_clearReceived(void);
u32 samsungIrDecoder_getReceivedWord(void);


#endif	

