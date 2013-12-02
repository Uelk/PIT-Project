#include "Signal.h"
using namespace std;

Signal::Signal() {
	signalTyp = unbekannt;
	quelle.clear();
	quellenTyp.clear();
	ziele [0].clear();
    ziele [1].clear();
    ziele [2].clear();
    ziele [3].clear();
    ziele [4].clear();
	anzahlZiele = 0;
}

Signal::~Signal() {
}

int Signal::getAnzahlZiele() {
	return anzahlZiele;
}

Signal::signalTypen Signal::getSignalTyp() {
    return signalTyp;
}

string Signal::getQuelle() {
    return quelle;
}

string Signal::getQuellenTyp() {
    return quellenTyp;
}

string Signal::getZiel( int pos ) {
    return ziele [pos];
}

void Signal::setAnzahlZiele( int nZiele ) {
    anzahlZiele = nZiele;
}

void Signal::setSignalTyp( signalTypen sigTyp ) {
    signalTyp = sigTyp;
}

void Signal::setQuelle( string gatterName ) {
    quelle = gatterName;
}

void Signal::setQuellenTyp( string gatterTyp ) {
    quellenTyp = gatterTyp;
}

void Signal::zielHinzufuegen( string gatterName, int pos ) {
    ziele [pos] = gatterName;
}