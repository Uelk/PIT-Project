#include "GatterTyp.h"
using namespace std;

GatterTyp::GatterTyp(){
}

GatterTyp::~GatterTyp(){
}

// Methoden und Eigenschaften
bool GatterTyp::getIsFlipflop() {
	return false;
}

string GatterTyp::getName() {
	return this->name;
}

double GatterTyp::getGrundLaufzeit() {
		return this->grundLaufzeit;
}

short GatterTyp::getLastFaktor() {
		return this->lastFaktor;
}

short GatterTyp::getLastKapazitaet() {
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