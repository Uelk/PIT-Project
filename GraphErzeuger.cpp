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
				endElement->setNextElement( new ListenElement() );
				endElement = endElement->getNextElement();
				endElement->setSchaltwerkElement( new SchaltwerkElement( bibliothek->getBibElement( signale[i].getQuellenTyp() )));
				endElement->getSchaltwerkElement()->setName( signale[i].getQuelle() );
			}
		} else {
			
		}
	}
	ueberpruefungUnbenutzesSignal();
	ueberpruefungUnbeschaltetesGatter();
	ueberpruefungAnzahlGatterZiele();
}

void GraphErzeuger::gatterZieleHinzufuegen() {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
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
	for( int i = 0; i<anzahlSignale; i++ ) {
		if( signale[i].getQuelle().find( gatterName ) != -1 ) {
			return &signale[i];
		}
	}
	return NULL;
}

SchaltwerkElement* GraphErzeuger::findeSchaltwerkElement( string gatterName ) {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		if( temporLE->getSchaltwerkElement()->getName().find( gatterName ) != -1 ) {
			return temporLE->getSchaltwerkElement();
		}
	}
	return NULL;
}

void GraphErzeuger::ueberpruefungUnbenutzesSignal() {
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( signale[i].getAnzahlZiele() == 0 && signale[i].getSignalTyp() != signale[i].ausgang) {
			cout << "Unbenutzes Signal Gefunden!" << endl;
			system("pause");
		}
	}
}

void GraphErzeuger::ueberpruefungUnbeschaltetesGatter() {

}

void GraphErzeuger::ueberpruefungAnzahlGatterZiele() {
}

void GraphErzeuger::ausgabeGraph() {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		cout << "Gattername: " << temporLE->getSchaltwerkElement()->getName() << endl;
		cout << "GatterTyp: " << temporLE->getSchaltwerkElement()->getTyp()->getName() << endl;
		cout << "--> Das Gatter hat " << temporLE->getSchaltwerkElement()->getAnzahlNachfolger() << " Ziele" << endl;
		cout << "Angeschlossene Gatter:";
		for (int i = 0; i < temporLE->getSchaltwerkElement()->getAnzahlNachfolger(); i++) {
			cout << " " << temporLE->getSchaltwerkElement()->getNachfolger(i)->getName();
		}
		cout << endl << endl;
	}
}