#include "FlipFlop.h"

FlipFlop::FlipFlop( void ) {}
FlipFlop::~FlipFlop( void ) {}

// Methoden und Eigenschaften
bool FlipFlop::getIsFlipFlop( void ) {
	return true;
}

short FlipFlop::getSetupTime() {
		return this->setupTime;
}

short FlipFlop::getHoldTime() {
		return this->holdTime;
}

short FlipFlop::getLastKapazitaetClock() {
	return lastKapazitaetClock;
}

void FlipFlop::setSetupTime( short st ) {
	this->setupTime = st;
}

void FlipFlop::setHoldTime( short ht ) {
	this->holdTime = ht;
}

void FlipFlop::setLastKapazitaetClock( short lkc ) {
	this->lastKapazitaetClock = lkc;
}