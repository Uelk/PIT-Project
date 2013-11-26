#include "Gattertyp.h"
using namespace std;

Gattertyp::Gattertyp( void ){
}

Gattertyp::~Gattertyp( void ){
}

//Methoden:
bool Gattertyp::getIsFlipflop( void ) {
	return false;
}

string Gattertyp::getName( void ) {
	return this->name;
}

double Gattertyp::getGrundLaufzeit( void ) {
		return this->grundLaufzeit;
}

short Gattertyp::getLastFaktor( void ) {
		return this->lastFaktor;
}

short Gattertyp::getLastKapazitaet( void ) {
		return this->lastKapazitaet;
}

short Gattertyp::getEingaenge() {
		return this->eingaenge;
}

void Gattertyp::setName( string n ) {
		this->name = n;
}

void Gattertyp::setGrundLaufzeit( double gl ) {
		this->grundLaufzeit = gl;
}

void Gattertyp::setLastFaktor( short lf ) {
		this->lastFaktor = lf;
}

void Gattertyp::setLastKapazitaet( short lk ) {
	    this->lastKapazitaet = lk;
}

void Gattertyp::setEingaenge( short ei ) {
		this->eingaenge = ei;
}