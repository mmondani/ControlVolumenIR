#ifndef PULSADOR_H
#define	PULSADOR_H

#include "basic_definitions.h"
#include "debounce.h"

/*****************************************************************************/
//  Funciones públicas
/*****************************************************************************/
void pulsador_init (u8* port, u8 pin);
void pulsador_handler (void);
u8 pulsador_isPressed (void);
void pulsador_clearPressed (void);
u8 pulsador_getNumber (void);



#endif	/* PULSADOR_H */

