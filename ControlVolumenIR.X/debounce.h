#ifndef DEBOUNCE_H
#define	DEBOUNCE_H

#include "basic_definitions.h"

#define         GPIO_ALTO_ACTIVO            1
#define         GPIO_BAJO_ACTIVO            0

#define         GPIO_SIN_FLANCO             0
#define         GPIO_FLANCO_A_ACTIVO        1
#define         GPIO_FLANCO_A_PASIVO        2

typedef struct
{
   u8* port;
   u8 nivelActivo;     // GPIO_ALTO_ACTIVO, GPIO_BAJO_ACTIVO
   u8 pin;             // Numero de 1 a 8
   u8 estado;          // BAJO = 0 y ALTO = 1
   u8 cont;            // acumulador
   u8 flanco;          // Cuando se produce un flanco
} gpio_t;

// Prototipos


void    debounce_Init       ( gpio_t* gpio, u8 nivelActivo, u8* puerto, u8 pin );
void    debounce_Handler    ( gpio_t* gpio);
u8      debounce_getEstado  ( gpio_t* gpio);
u8      debounce_getFlanco  ( gpio_t* gpio);

#endif	/* DEBOUNCE_H */

