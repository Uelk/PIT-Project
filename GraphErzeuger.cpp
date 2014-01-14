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

ListenElement* GraphErzeuger::getStartElement() {
	return startElement;
}

void GraphErzeuger::erzeugeGraph() {
	erzeugeListe();
	gatterZieleHinzufuegen();
	ueberpruefungUnbenutzesSignal();
	ueberpruefungGatterBeschaltung();
}

void GraphErzeuger::erzeugeListe() {
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( !signale[i].getQuelle().empty() ) {
			if( startElement == NULL ) { // erstes Listenelement samt SchaltwerkElement hinzufuegen
				startElement = new ListenElement();
				endElement = startElement;
				startElement->setSchaltwerkElement( new SchaltwerkElement( bibliothek->getBibElement( signale[i].getQuellenTyp() )));
				endElement->getSchaltwerkElement()->setName( signale[i].getQuelle() );
			} else { // folgende Listenelemente samt SchaltwerkElement hinzufuegen
				endElement->setNextElement( new ListenElement() );
				endElement = endElement->getNextElement();
				endElement->setSchaltwerkElement( new SchaltwerkElement( bibliothek->getBibElement( signale[i].getQuellenTyp() )));
				endElement->getSchaltwerkElement()->setName( signale[i].getQuelle() );
			}
		} else { //<<<<<<<<< Fehlermeldung
			
		}
	}
}

// Funktion zum Eintragen der Quellen und Ziele in die vorhandene Liste
void GraphErzeuger::gatterZieleHinzufuegen() {
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( signale[i].getSignalTyp() == signale[i].eingang ) { // Eingangssignal nur mit Ziel
			for( int j = 0; j < signale[i].getAnzahlZiele(); j++ ) {
				SchaltwerkElement* zielElement = findeSchaltwerkElement( signale[i].getZiel(j) );
				zielElement->setAnzahlEingangssignale( zielElement->getAnzahlEingangssignale() + 1 );
				// Merker fuer Eingangselement setzen
				zielElement->setIsEingangsElement( true );
			}
		}
		if( signale[i].getSignalTyp() == signale[i].ausgang ) {
			SchaltwerkElement* quellenElement = findeSchaltwerkElement( signale[i].getQuelle() );
			// Merker fuer Ausgangselement Setzen
			quellenElement->setIsAusgangsElement( true );
		}
		if( signale[i].getSignalTyp() == signale[i].intern ) { // Interne Signale mit Quelle und Ziel
			SchaltwerkElement* quellenElement = findeSchaltwerkElement( signale[i].getQuelle() );
			for( int j = 0; j < signale[i].getAnzahlZiele(); j++ ) {
				SchaltwerkElement* zielElement = findeSchaltwerkElement( signale[i].getZiel(j) );
				quellenElement->nachfolgerHinzufuegen( zielElement, quellenElement->getAnzahlNachfolger() );
				// Variable für Anzahl der Nachfolger Inkrementieren
				quellenElement->setAnzahlNachfolger( quellenElement->getAnzahlNachfolger() + 1 );
				// Variable für Anzahl der Eingangssignale des Ziels Inkrementieren
				zielElement->setAnzahlEingangssignale( zielElement->getAnzahlEingangssignale() + 1 );
			}
		}
	}
}

// Zum Gatter zugehoeriges Ausgangssignal finden
Signal* GraphErzeuger::findeSignal( string gatterName ) {  //<<<<<< Gattername bei findeSignal() und findeSWE()?
	for( int i = 0; i<anzahlSignale; i++ ) {
		if( signale[i].getQuelle().find( gatterName ) != -1 ) {
			return &signale[i];
		}
	}
	return NULL;
}

// Zum Gatter zugehoeriges SchaltwerkElement finden
SchaltwerkElement* GraphErzeuger::findeSchaltwerkElement( string gatterName ) {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		if( temporLE->getSchaltwerkElement()->getName().find( gatterName ) != -1 ) {
			return temporLE->getSchaltwerkElement();
		}
	}
	return NULL;
}

// Ueberpruefen, ob ein Signal vom Typ EINGANG, oder INTERN unbenutzt ist
void GraphErzeuger::ueberpruefungUnbenutzesSignal() {
	for( int i = 0; i < anzahlSignale; i++ ) {
		if( signale[i].getAnzahlZiele() == 0 && signale[i].getSignalTyp() != signale[i].ausgang) {
			cout << "Unbenutzes Signal Gefunden!" << endl;
			system( "pause" );
		}
	}
}

void GraphErzeuger::ueberpruefungGatterBeschaltung() {
	short anzahlGatterEingaenge;
	short anzahlBeschalteterGatterEingaenge;

	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		anzahlGatterEingaenge = temporLE->getSchaltwerkElement()->getTyp()->getEingaenge();
		anzahlBeschalteterGatterEingaenge = temporLE->getSchaltwerkElement()->getAnzahlEingangssignale();
		if( anzahlBeschalteterGatterEingaenge == 0 ) { // voellig unbeschaltet
			cout << "Gaenzlich unbeschaltetes Gatter gefunden:" << temporLE->getSchaltwerkElement()->getName() << endl;
			system( "pause" );
		} else {
			if( anzahlBeschalteterGatterEingaenge < anzahlGatterEingaenge ) { // teilweise unbeschaltet
				cout << "Teilweise unbeschaltetes Gatter gefunden:" << temporLE->getSchaltwerkElement()->getName() << endl;
				system( "pause" );
			}
		}
	}
}

void GraphErzeuger::ausgabeGraph() {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		cout << "Gattername: " << temporLE->getSchaltwerkElement()->getName() << endl;
		cout << "GatterTyp: " << temporLE->getSchaltwerkElement()->getTyp()->getName() << endl;
		cout << "--> Das Gatter hat " << temporLE->getSchaltwerkElement()->getAnzahlNachfolger() << " Ziele" << endl;
		cout << "Angeschlossene Gatter:";
		for ( int i = 0; i < temporLE->getSchaltwerkElement()->getAnzahlNachfolger(); i++ ) {
			cout << " " << temporLE->getSchaltwerkElement()->getNachfolger(i)->getName();
		}
		cout << endl << endl;
	}
}