#ifndef GRAPHERZEUGER_H
#define GRAPHERZEUGER_H

#include <iostream>
#include "Bibliothek.h"
#include "Signal.h"
#include "ListenElement.h"
#include "GatterTyp.h"
using namespace std;

class GraphErzeuger {
private:
	Bibliothek* bibliothek;
	ListenElement* startElement;
	ListenElement* endElement;
	Signal* signale;
	short anzahlSignale;
public:
	GraphErzeuger();
	~GraphErzeuger();
	void setBibliothek( Bibliothek* );
	void setSignale( Signal*, short );
	void erzeugeGraph();
	void erzeugeListe();
	void gatterZieleHinzufuegen();
	Signal* findeSignal( string );
	SchaltwerkElement* findeSchaltwerkElement( string );
	void ueberpruefungUnbenutzesSignal();
	void ueberpruefungGatterBeschaltung();
	void ausgabeGraph();
};
#endif