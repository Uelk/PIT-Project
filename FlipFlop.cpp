#include "Flipflop.h"


Flipflop::Flipflop( void ) {}
Flipflop::~Flipflop( void ) {}

//Methoden:
bool Flipflop::getIsFlipflop( void ) {
	return true;
}

short Flipflop::getSetupTime() {
		return this->setupTime;
}

short Flipflop::getHoldTime() {
		return this->holdTime;
}

short Flipflop::getLastKapazitaetClock() {
	return lastKapazitaetClock;
}

void Flipflop::setSetupTime( short st ) {
	this->setupTime = st;
}

void Flipflop::setHoldTime( short ht ) {
	this->holdTime = ht;
}

void Flipflop::setLastKapazitaetClock( short lkc ) {
	this->lastKapazitaetClock = lkc;
}