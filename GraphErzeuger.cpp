#include "GraphErzeuger.h"
#include "GatterTyp.h"
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
	startElement->setSchaltwerkElement( new SchaltwerkElement( new GatterTyp() ));
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( !signale[i].getQuelle().empty() ) {
			if( startElement == endElement ) {
				saveSchaltwerkElementData(startElement->getSchaltwerkElement(), signale[i]);
			} else {
				endElement = new ListenElement();
				endElement->setSchaltwerkElement( new SchaltwerkElement( new GatterTyp() ));
				saveSchaltwerkElementData(startElement->getSchaltwerkElement(), signale[i]);
			}
		}
	}
}

void GraphErzeuger::saveSchaltwerkElementData( SchaltwerkElement* schaltwerkElement, Signal curSignal ) {
	schaltwerkElement->setName( curSignal.getQuelle() );
	schaltwerkElement->setAnzahlNachfolger( curSignal.getAnzahlZiele() );
	for( int i = 0; i < curSignal.getAnzahlZiele(); i++ ) {
		//schaltwerkElement->nachfolgerHinzufuegen();
	}
}

void GraphErzeuger::ausgabeGraph() {
	for(ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement()) {
		cout << "Gattername: " << temporLE->getSchaltwerkElement()->getName() << endl;
		cout << "GatterTyp: " << temporLE->getSchaltwerkElement()->getTyp()->getName() << endl;
		cout << "--> Das Gatter hat " << temporLE->getSchaltwerkElement()->getAnzahlNachfolger() << (( temporLE->getSchaltwerkElement()->getAnzahlNachfolger()) == 1 ? " Ziel" : " Ziele") << endl;
		cout << "Angeschlossene Gatter:";
		for (int j = 0; j < temporLE->getSchaltwerkElement()->getAnzahlNachfolger(); j++) {
			cout << " " << temporLE->getSchaltwerkElement()->getNachfolger(j)->getName();
		}
		cout << endl << endl;
	}
}