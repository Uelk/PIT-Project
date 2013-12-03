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
	erzeugeListe();
	gatterZieleHinzufuegen();
}

void GraphErzeuger::erzeugeListe() {
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( !signale[i].getQuelle().empty() ) {
			if( startElement == NULL ) {
				startElement = new ListenElement();
				endElement = startElement;
				startElement->setSchaltwerkElement( new SchaltwerkElement( bibliothek->getBibElement( signale[i].getQuellenTyp() )));
				endElement->getSchaltwerkElement()->setName( signale[i].getQuelle() );
			} else {
				endElement = new ListenElement();
				endElement->setSchaltwerkElement( new SchaltwerkElement( bibliothek->getBibElement( signale[i].getQuellenTyp() )));
				endElement->getSchaltwerkElement()->setName( signale[i].getQuelle() );
			}
		} else {
			if( signale[i].getAnzahlZiele() == 0 ) {
				cout << "Unbenutzes Eingangssignal Gefunden!" << endl;
				system("pause");
			}
		}
	}
}

void GraphErzeuger::gatterZieleHinzufuegen() {
	for(ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement()) {
		Signal* korrespondSignal = findeSignal( temporLE->getSchaltwerkElement()->getName() );
		SchaltwerkElement* curSchaltwerkElement = temporLE->getSchaltwerkElement();
		for( int i = 0; i<korrespondSignal->getAnzahlZiele(); i++ ) {
			curSchaltwerkElement->nachfolgerHinzufuegen( findeSchaltwerkElement( korrespondSignal->getZiel(i) ), 
				curSchaltwerkElement->getAnzahlNachfolger() );
			curSchaltwerkElement->setAnzahlNachfolger( curSchaltwerkElement->getAnzahlNachfolger() + 1 );
		}
	}
}

Signal* GraphErzeuger::findeSignal( string gatterName ) {
	for( int i = 0; i<anzahlSignale; i++) {
		if( signale[i].getQuelle().find( gatterName ) != -1 ) {
			return &signale[i];
		}
	}
	return NULL;
}

SchaltwerkElement* GraphErzeuger::findeSchaltwerkElement( string gatterName ) {
	for(ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement()) {
		if( temporLE->getSchaltwerkElement()->getName().find( gatterName ) != -1 ) {
			return temporLE->getSchaltwerkElement();
		}
	}
	return NULL;
}

void GraphErzeuger::ausgabeGraph() {
	for(ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement()) {
		cout << "Gattername: " << temporLE->getSchaltwerkElement()->getName() << endl;
		/*cout << "GatterTyp: " << temporLE->getSchaltwerkElement()->getTyp()->getName() << endl;
		cout << "--> Das Gatter hat " << temporLE->getSchaltwerkElement()->getAnzahlNachfolger() << (( temporLE->getSchaltwerkElement()->getAnzahlNachfolger()) == 1 ? " Ziel" : " Ziele") << endl;
		cout << "Angeschlossene Gatter:";
		for (int j = 0; j < temporLE->getSchaltwerkElement()->getAnzahlNachfolger(); j++) {
			cout << " " << temporLE->getSchaltwerkElement()->getNachfolger(j)->getName();
		}
		cout << endl << endl;*/
	}
	system("pause");
}