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

// Rückgabe Anzahl Ziele
int Signal::getAnzahlZiele() {
	return anzahlZiele;
}

// Rückgabe Signaltyp
Signal::signalTypen Signal::getSignalTyp() {
    return signalTyp;
}

// Rückgabe Quelle
string Signal::getQuelle() {
    return quelle;
}

// Rückgabe Quellentyp
string Signal::getQuellenTyp() {
    return quellenTyp;
}

// Rückgabe Ziel
string Signal::getZiel( int pos ) {
    return ziele [pos];
}

// Anzahl der Ziele bestimmen
void Signal::setAnzahlZiele( int nZiele ) {
    anzahlZiele = nZiele;
}

// Signaltyp bestimmen
void Signal::setSignalTyp( signalTypen sigTyp ) {
    signalTyp = sigTyp;
}

// Quelle bestimmen
void Signal::setQuelle( string gatterName ) {
    quelle = gatterName;
}

// Quellentyp bestimmen
void Signal::setQuellenTyp( string GatterTyp ) {
    quellenTyp = GatterTyp;
}

// Ziel hinzufügen
void Signal::zielHinzufuegen( string gatterName, int pos ) {
    ziele [pos] = gatterName;
}