#include <string>
#include "SchaltwerkElement.h"
using namespace std;

SchaltwerkElement::SchaltwerkElement( void ) {
	name = "";
	laufzeitEinzelgatter = 0;
	anzahlNachfolger = 0;
	isEingangsElement = NULL;
	isAusgangsElement = NULL;
	anzahlEingangssignale = 0;
}

SchaltwerkElement::SchaltwerkElement( Gattertyp* gTyp ) {
	SchaltwerkElement::name.clear();
	typ = gTyp;
	laufzeitEinzelgatter = 0.0;
//	nachfolgerElemente* = NULL;
	anzahlNachfolger = 0;
	isEingangsElement = NULL;
	isAusgangsElement = NULL;
	anzahlEingangssignale = 0.0;
}


SchaltwerkElement::~SchaltwerkElement() {
}

string SchaltwerkElement::getName() {
	return name;
}

Gattertyp* SchaltwerkElement::getTyp() {
	return typ;
}

double SchaltwerkElement::getLaufzeitEinzelgatter() {
	return laufzeitEinzelgatter;
}

SchaltwerkElement* SchaltwerkElement::getNachfolger( int pos ) {
	return nachfolgerElemente[pos];
}

int SchaltwerkElement::getAnzahlNachfolger() {
	return anzahlNachfolger;
}

short SchaltwerkElement::getAnzahlEingangssignale() {
	return anzahlEingangssignale;
}

bool SchaltwerkElement::getIsEingangsElement() {
	return isEingangsElement;
}

bool SchaltwerkElement::getIsAusgangsElement() {
	return isAusgangsElement;
}

void SchaltwerkElement::setName( string n ) {
	name = n;
}

void SchaltwerkElement::nachfolgerHinzufuegen( SchaltwerkElement* schaltwerkElement, int pos ) {
	nachfolgerElemente[pos] = schaltwerkElement;
}

void SchaltwerkElement::setAnzahlNachfolger( int anzahlN ) {
	anzahlNachfolger = anzahlN;
}

void SchaltwerkElement::setAnzahlEingangssignale( short anzahlE ) {
	anzahlEingangssignale = anzahlE;
}

void SchaltwerkElement::setIsEingangsElement( bool isEingangsEl ) {
	isEingangsElement = isEingangsEl;
}

void SchaltwerkElement::setIsAusgangsElement( bool isAusgangsEl ) {
	isAusgangsElement = isAusgangsEl;
}

void SchaltwerkElement::setLaufzeitEinzelgatter( double lfz ) {
	laufzeitEinzelgatter = lfz;
}