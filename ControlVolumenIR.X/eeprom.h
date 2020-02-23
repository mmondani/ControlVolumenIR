#ifndef EEPROM_H
#define	EEPROM_H

#include "project.h"
#include "basic_definitions.h"

/*****************************************************************************/
//  PROTOTIPOS
/*****************************************************************************/

/*****************************************************************************/
//  eeprom_wr
/*****************************************************************************
 *  Descripci�n: escribe la posici�n addr de la EEPROM con data.
 *
 *  Entradas: addr - direcci�n de la EEPROM a escribir
 *            data - dato a escribir.
 *            check - si es 1 se lee lo escrito para comprobar que est� bien.
 *
 *  Salidas:
 *
 *****************************************************************************/
void eeprom_wr (u8 addr, u8 data, u8 check);


/*****************************************************************************/
//  eeprom_rd
/*****************************************************************************
 *  Descripci�n: lee la posici�n addr de la EEPROM.
 *
 *  Entradas: addr - posici�n de la EEPROM a leer.
 *
 *  Salidas: dato leido.
 *
 *****************************************************************************/
u8 eeprom_rd  (u8 addr);



#endif	/* EEPROM_H */

