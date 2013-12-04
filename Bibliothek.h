#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H

#include <iostream >
#include <fstream>
#include <string>
#include <vector>
#include "GatterTyp.h"
#include "FlipFlop.h"
using namespace std;

class Bibliothek {
private:
    vector <GatterTyp*> bibElemente;
    string datei;
    bool errFileNotFound;
    bool errFileRead;
public:
	Bibliothek();
	~Bibliothek();
    
    //Methoden
    string getPfad(); //Pfad und Dateinamen auslesen
	GatterTyp* getBibElement( string typ );
	void dateiAusgabe(); //Ausgabe der Datei auf den Bildschirm
	void dateiAuswerten(); //Einlesen und Auswerten der Bib-Datei
	bool pfadEinlesen ( string pfad ); //Pfad zur Bib-Datei in Attribut spreichern
	void openError(); //Fehler beim šffnen der Datei
	void readError(); //Fehler beim Lesen der Datei
};
#endif
