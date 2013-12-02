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
	for( int i; i < anzahlSignale; i++ ) {
		if( signale[i].getSignalTyp == signale[i].intern ) {
			if(startElement =endElement) {
				startElement->setSchaltwerkElement(new SchaltwerkElement());
			} else {
				g
			}
		}
	}
}

void ausgabeGraph() {
	cout << "Graphstruktur" << endl;
	cout << "-------" << endl;
	cout << "Gattername" << endl;
	cout << "Gattertyp" << endl;
	cout << "Das Gatter hat " << "Ziele" << endl;
	cout << "Angeschlossene Gatter" << endl;
}