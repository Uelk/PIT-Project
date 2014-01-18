/* 
    Windows-Treiber f�r das ITIV-Windows-Ger�t
    ------------------------------------------
    
    Autor:              Stephan Werner
    letzte �nderung:    07.09.2013
*/

#ifndef ITIV_WIN_DRV_H
#define ITIV_WIN_DRV_H

#include <stdint.h>

/*
	Struktur f�r die Ger�te-Konfiguration
*/
typedef struct {
    uint32_t    DeviceId;
    volatile uint8_t*    BaseAddress;
} ItivDev_Config;


#define	CTRL_REG	0x00000000
#define	STAT_REG	0x00000004
#define	DATA_REG	0x00000008

/*
	Initialisieren der Ger�testruktur

	Die Funktion nimmt den Ger�tenamen entgegen, um die
	Konfiguration des Ger�tes zu ermitteln.
	Zur�ckgegeben wird ein Pointer auf eine Struktur vom Typ
		ItivDev_Config
	Der Pointer zeigt auf eine Struktur, welche die Hardware-ID
	und die Basisadresse enth�lt.
*/
extern ItivDev_Config* ItivDev_GetConfigByName(const char* DevName);

/*
	Freigeben des Ger�tes

	Um das Ger�t wieder freizugeben, muss der Pointer als
	Argument �bergeben werden, der zuvor von der Init-Funktion
	zur�ckgegeben wurde.
*/
extern uint32_t ItivDev_ReleaseDevice(ItivDev_Config* DevStructure);

#endif