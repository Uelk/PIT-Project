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
		schaltwerkElement->nachfolgerHinzufuegen();
	}
}


void GraphErzeuger::ausgabeGraph() {

	for(int i = 0; i<anzahlElemente;i++)
        {
                int anzahlNachfolger = signale->getSchaltwerkElement()->getAnzahlNachfolger();
                cout << "Gattername: " << ~LISTENELEMENT~->getSchaltwerkElement()->getName() << endl;
                cout << "Gattertyp: " << ~LISTENELEMENT~->getSchaltwerkElement()->getTyp()->getName() << endl;
                cout << "--> Das Gatter hat " << anzahlNachfolger << (anzahlNachfolger == 1 ? " Ziel" : " Ziele") << endl;
                cout << "Angeschlossene Gatter:";
                for (int j = 0; j < anzahlNachfolger; j++)
                {
                        cout << " " << ~LISTENELEMENT~->getSchaltwerkElement()->getNachfolger(j)->getName();
                }
                cout << endl << endl;

                ~LISTENELEMENT~ = tempLE->getNextElement();
        }
        system("pause");
}

/*else{
		 cout << "Fehler! Ein unbenutztes Signal wurde gefunden\n";
         system("pause");
		}*/