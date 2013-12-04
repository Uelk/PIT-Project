#ifndef FlipFlop_H
#define FlipFlop_H

#include "GatterTyp.h"
using namespace std;

class FlipFlop : public GatterTyp {
private:
    short setupTime;
    short holdTime;
    short lastKapazitaetClock;
public:
    FlipFlop( void );
    ~FlipFlop( void );
    
    //Methoden
    bool getIsFlipFlop( void );
    short getSetupTime();
    short getHoldTime();
	short getLastKapazitaetClock();
	void setSetupTime( short st );
	void setHoldTime( short ht );
	void setLastKapazitaetClock( short lkc );
};
#endif
