#include "GatterTyp.h"
using namespace std;

GatterTyp::GatterTyp(){
}

GatterTyp::~GatterTyp(){
}

// Methoden und Eigenschaften
bool GatterTyp::getIsFlipflop( void ) {
	return false;
}

string GatterTyp::getName( void ) {
	return this->name;
}

double GatterTyp::getGrundLaufzeit( void ) {
		return this->grundLaufzeit;
}

short GatterTyp::getLastFaktor( void ) {
		return this->lastFaktor;
}

short GatterTyp::getLastKapazitaet( void ) {
		return this->lastKapazitaet;
}

short GatterTyp::getEingaenge() {
		return this->eingaenge;
}

void GatterTyp::setName( string n ) {
		this->name = n;
}

void GatterTyp::setGrundLaufzeit( double gl ) {
		this->grundLaufzeit = gl;
}

void GatterTyp::setLastFaktor( short lf ) {
		this->lastFaktor = lf;
}

void GatterTyp::setLastKapazitaet( short lk ) {
	    this->lastKapazitaet = lk;
}

void GatterTyp::setEingaenge( short ei ) {
		this->eingaenge = ei;
}