#include "GatterTyp.h"
using namespace std;

GatterTyp::GatterTyp(){
}

GatterTyp::~GatterTyp(){
}

// Methoden und Eigenschaften
bool GatterTyp::getIsFlipFlop() {
	return false;
}

string GatterTyp::getName() {
	return name;
}

double GatterTyp::getGrundLaufzeit() {
		return grundLaufzeit;
}

short GatterTyp::getLastFaktor() {
		return lastFaktor;
}

short GatterTyp::getLastKapazitaet() {
		return lastKapazitaet;
}

short GatterTyp::getEingaenge() {
		return eingaenge;
}

void GatterTyp::setName( string n ) {
		name = n;
}

void GatterTyp::setGrundLaufzeit( double gl ) {
		grundLaufzeit = gl;
}

void GatterTyp::setLastFaktor( short lf ) {
		lastFaktor = lf;
}

void GatterTyp::setLastKapazitaet( short lk ) {
	    lastKapazitaet = lk;
}

void GatterTyp::setEingaenge( short ei ) {
		eingaenge = ei;
}