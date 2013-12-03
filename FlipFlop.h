#ifndef FLIPFLOP_H
#define FLIPFLOP_H

#pragma once
#include "GatterTyp.h"
using namespace std;

class Flipflop : public GatterTyp {
private:
    short setupTime;
    short holdTime;
    short lastKapazitaetClock;
public:
    Flipflop( void );
    ~Flipflop( void );
    
    //Methoden
    bool getIsFlipflop( void );
    short getSetupTime();
    short getHoldTime();
	short getLastKapazitaetClock();
	void setSetupTime( short st );
	void setHoldTime( short ht );
	void setLastKapazitaetClock( short lkc );
};
#endif
