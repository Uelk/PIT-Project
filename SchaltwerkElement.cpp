#include <string>
#include "SchaltwerkElement.h"
using namespace std;

// Alle Attribute mit Wert 0 bzw. NULL initialisieren
SchaltwerkElement::SchaltwerkElement( Gattertyp* gTyp ) {
	SchaltwerkElement::name.clear();
	typ = gTyp;
	laufzeitEinzelgatter = 0.0;
	nachfolgerElemente[0] = NULL;
	nachfolgerElemente[1] = NULL;
	nachfolgerElemente[2] = NULL;
	nachfolgerElemente[3] = NULL;
	nachfolgerElemente[4] = NULL;
	anzahlNachfolger = 0;
	isEingangsElement = NULL;
	isAusgangsElement = NULL;
	anzahlEingangssignale = 0.0;
}

SchaltwerkElement::~SchaltwerkElement() {
}

// Rückgabe Name
string SchaltwerkElement::getName() {
	return name;
}

// Rückgabe Typ
Gattertyp* SchaltwerkElement::getTyp() {
	return typ;
}

// Rückgabe Laufzeit des Einzelgatters
double SchaltwerkElement::getLaufzeitEinzelgatter() {
	return laufzeitEinzelgatter;
}

// Rückgabe der Nachfolgerelemente
SchaltwerkElement* SchaltwerkElement::getNachfolger( int pos ) {
	return nachfolgerElemente[pos];
}

// Rückgabe Anzahl der Nachfolger
int SchaltwerkElement::getAnzahlNachfolger() {
	return anzahlNachfolger;
}

// Rückgabe Anzahl der Eingangssignale
short SchaltwerkElement::getAnzahlEingangssignale() {
	return anzahlEingangssignale;
}

// Rückgabe des Eingangelements
bool SchaltwerkElement::getIsEingangsElement() {
	return isEingangsElement;
}

// Rückgabe des Ausgangelements
bool SchaltwerkElement::getIsAusgangsElement() {
	return isAusgangsElement;
}

// Name festlegen
void SchaltwerkElement::setName( string n ) {
	name = n;
}

// Nachfolgeelemente festlegen
void SchaltwerkElement::nachfolgerHinzufuegen( SchaltwerkElement* schaltwerkElement, int pos ) {
	nachfolgerElemente[pos] = schaltwerkElement;
}

// Anzahl Nachfolger festlegen
void SchaltwerkElement::setAnzahlNachfolger( int anzahlN ) {
	anzahlNachfolger = anzahlN;
}

// Anzahl Eingangssignale festlegen
void SchaltwerkElement::setAnzahlEingangssignale( short anzahlE ) {
	anzahlEingangssignale = anzahlE;
}

// Eingangselemente festlegen
void SchaltwerkElement::setIsEingangsElement( bool isEingangsEl ) {
	isEingangsElement = isEingangsEl;
}

// Ausgangselemente festlegen
void SchaltwerkElement::setIsAusgangsElement( bool isAusgangsEl ) {
	isAusgangsElement = isAusgangsEl;
}

// Laufzeit des Einzelgatters festlegen
void SchaltwerkElement::setLaufzeitEinzelgatter( double lfz ) {
	laufzeitEinzelgatter = lfz;
}