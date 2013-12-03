#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H

#pragma once
#include <iostream >
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "GatterTyp.h"
#include "Flipflop.h"
#include "helper.h"
#include <Windows.h>
#include <cstdio>
using namespace std;


class Bibliothek {
private:
    vector <GatterTyp*> bibElemente;
    string datei;
    bool errFileNotFound;
    bool errFileRead;
    bool errElNotInVec;
public:
	Bibliothek( void );
	~Bibliothek( void );
    
    //Methoden
    string getPfad(); //Pfad und Dateinamen auslesen
	GatterTyp* getBibElement( string typ );
	void dateiAusgabe( void ); //Ausgabe der Datei auf den Bildschirm
	void dateiAuswerten( void ); //Einlesen und Auswerten der Bib-Datei
	bool pfadEinlesen ( string pfad ); //Pfad zur Bib-Datei in Atribut spreichern
	void openError( void ); //Fehler beim šffnen der Datei
	void readError( void ); //Fehler beim Lesen der Datei
	bool vecError( void ); //Wurde das gesuchte Element in dem Vector gefunden?
};
#endif
