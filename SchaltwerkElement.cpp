#include <string>
#include "SchaltwerkElement.h"
using namespace std;

// Alle Attribute mit Wert 0 bzw. NULL initialisieren
SchaltwerkElement::SchaltwerkElement( GatterTyp* gTyp ) {
	name.clear();
	typ = gTyp;
	LaufzeitEinzelgatter = 0.0;
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

// Rueckgabe Name
string SchaltwerkElement::getName() {
	return name;
}

// Rueckgabe Typ
GatterTyp* SchaltwerkElement::getTyp() {
	return typ;
}

// Rueckgabe Laufzeit des Einzelgatters
double SchaltwerkElement::getLaufzeitEinzelgatter() {
	return LaufzeitEinzelgatter;
}

// Rueckgabe der Nachfolgerelemente
SchaltwerkElement* SchaltwerkElement::getNachfolger( int pos ) {
	return nachfolgerElemente[pos];
}

// Rueckgabe Anzahl der Nachfolger
int SchaltwerkElement::getAnzahlNachfolger() {
	return anzahlNachfolger;
}

// Rueckgabe Anzahl der Eingangssignale
short SchaltwerkElement::getAnzahlEingangssignale() {
	return anzahlEingangssignale;
}

// Rueckgabe des Eingangelements
bool SchaltwerkElement::getIsEingangsElement() {
	return isEingangsElement;
}

// Rueckgabe des Ausgangelements
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
	LaufzeitEinzelgatter = lfz;
}