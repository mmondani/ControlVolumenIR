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
//  Funciones p�blicas
/*****************************************************************************/

/*****************************************************************************/
//  eeData_init
/*****************************************************************************
 *  Descripci�n: inicializa el m�dulo EEDATA. Debe ser llamada al comienzo
 *               de la aplicaci�n.
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
 *  Descripci�n: realiza un chequeo de la EEPROM para determinar si es necesario
 *               inicializarla. Si est� inicializada, se recuperan los valores.
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
 *  Descripci�n: fui�n que es llamada por eeData_checkEEPROM para inicializar
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
 *  Descripci�n: funci�n qu es llamada por eeData_loadValues para recuperar los
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
 *  Descripci�n: guarda en la EEPROM la EEDATA.
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
 *  Descripci�n: le indica a eeData que tiene que guardar en EEPROM un �rea de 
 *               RAM.
 *
 *  Entradas: -
 *
 *  Salidas: -
 *
 *****************************************************************************/
void eeData_enqueueSave (u8 address, u8 cant);

#endif	/* EEPROMMAP_H */

