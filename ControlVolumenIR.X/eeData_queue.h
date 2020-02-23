#include "project.h"

#ifndef EEPROMMAP_H
#define	EEPROMMAP_H


#include "basic_definitions.h"


/*****************************************************************************/
//  DEFINICIONES
/*****************************************************************************/
#define EEDATA_SAVE_QUEUE_LENGTH     5


/*****************************************************************************/
//  MAPA DE MEMORIA EEPROM
/*****************************************************************************/
#define EE_MAP_LENGTH           9         // Cantidad total de bytes usados en la EEPROM
u8 EEData[EE_MAP_LENGTH];

// Campos
#define EE_VERSION              EEData[0]
#define EE_WORD_UP              EEData[1]
#define EE_WORD_DOWN            EEData[5]


// Direcciones
#define EE_VERSION_ADDR           0
#define EE_WORD_UP_ADDR           1
#define EE_WORD_DOWN_ADDR         5


#define EE_FIRST_POSITION       EE_VERSION_ADDR
/****************************************************************************/


/*****************************************************************************/
//  Funciones públicas
/*****************************************************************************/

/*****************************************************************************/
//  eeData_init
/*****************************************************************************
 *  Descripción: inicializa el módulo EEDATA. Debe ser llamada al comienzo
 *               de la aplicación.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_init (void);


/*****************************************************************************/
//  eeData_checkEEPROM
/*****************************************************************************
 *  Descripción: realiza un chequeo de la EEPROM para determinar si es necesario
 *               inicializarla. Si está inicializada, se recuperan los valores.
 *               Si no, se la inicializa.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_checkEEPROM (void);


/*****************************************************************************/
//  eeData_defaults
/*****************************************************************************
 *  Descripción: fuión que es llamada por eeData_checkEEPROM para inicializar
 *               la EEPROM. DEBE ser modificada por el usuario de acuerdo al
 *               proyecto.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_defaults (void);


/*****************************************************************************/
//  eeData_loadValues
/*****************************************************************************
 *  Descripción: función qu es llamada por eeData_loadValues para recuperar los
 *               datos de la EEPROM. DEBE ser modificada por el usario de
 *               acuerdo al proyecto.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_loadValues (void);


/*****************************************************************************/
//  eeData_saveRAM
/*****************************************************************************
 *  Descripción: guarda en la EEPROM la EEDATA.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_saveRAM (void);



/*****************************************************************************/
//  eeData_saveRAM
/*****************************************************************************
 *  Descripción: le indica a eeData que tiene que guardar en EEPROM un área de 
 *               RAM.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_enqueueSave (u8 address, u8 cant);

#endif	/* EEPROMMAP_H */

