#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H

#include <string>
#include <iostream>
#include <fstream>
#include "Signal.h"
using namespace std;

class SignalListeErzeuger {
private:
	Signal* signale;
	short anzahlSignale;
	string datei;
	string line;
	string input;
	string output;
	string signals;
	string clockName;
	string schaltnetz;
	long frequenz;
	void dateiAuslesen();
	void inputsAuslesen();
	void outputsAuslesen();
	void signalsAuslesen();
	void clockAuslesen();
	void signalTypenErkennung();
	void schaltnetzwerkBeschreibungAuslesen();
	bool isInput( string );
	bool isOutput( string );
	bool isSignal( string );
public:
	SignalListeErzeuger();
	int getAnzahlSignale();
	bool setDateiPfad( string );
	string getDateiPfad();
	void ausgabeDatei();
	Signal* getSignalListe();
	void ausgabeSignale();
};
#endif