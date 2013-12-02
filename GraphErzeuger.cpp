#include "GraphErzeuger.h"

using namespace std;

GraphErzeuger::GraphErzeuger() {
}

GraphErzeuger::~GraphErzeuger() {
}

void GraphErzeuger::setBibliothek( Bibliothek* bib ) {
	bibliothek = bib;
}

void GraphErzeuger::setSignale( Signal* sig, short anz ) {
	signale = sig;
	anzahlSignale = anz;
}

void GraphErzeuger::erzeugeGraph() {
	startElement = new ListenElement();
	endElement = startElement;
	startElement->setSchaltwerkElement(new SchaltwerkElement());
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( !signale[i].getQuelle().empty() ) {
			if( startElement == endElement ) {
				saveSchaltwerkElementData(startElement->getSchaltwerkElement(), signale[i]);
			}
		}
	}
}

void saveSchaltwerkElementData( SchaltwerkElement* schaltwerkElement, Signal curSignal ) {
	schaltwerkElement->setName( curSignal.getQuelle() );
	schaltwerkElement->setAnzahlNachfolger( curSignal.getAnzahlZiele() );
	for( int i = 0; i < curSignal.getAnzahlZiele(); i++ ) {
		//schaltwerkElement->nachfolgerHinzufuegen();
	}
}

void GraphErzeuger::ausgabeGraph() {
	ListenElement* l = endElement;
	cout << "Graphstruktur" << endl;
	cout << "-------" << endl;
	cout << "Gattername" << endl;
	cout << "Gattertyp" << endl;
	cout << "Das Gatter hat " << "Ziele" << endl;
	cout << "Angeschlossene Gatter" << endl;
}