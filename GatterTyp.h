#ifndef GatterTyp_H
#define GatterTyp_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

class GatterTyp {
public:
    GatterTyp();
    ~GatterTyp();
    
    //Methoden
	string getName();
	double getGrundLaufzeit();
	short getLastFaktor();
	short getLastKapazitaet();
	short getEingaenge();
	virtual	bool getIsFlipFlop();
	void setName( string );
	void setGrundLaufzeit( double );
	void setLastFaktor( short );
	void setEingaenge( short );
	void setLastKapazitaet( short );
protected:
    //Attribute:
	string name;
	double grundLaufzeit;
	short lastFaktor;
	short lastKapazitaet;
	short eingaenge;
};
#endif

