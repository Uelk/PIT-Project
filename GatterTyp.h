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
	virtual	bool getIsFlipflop( void );
	void setName( string n );
	void setGrundLaufzeit( double gl );
	void setLastFaktor( short lf );
	void setEingaenge( short ei );
	void setLastKapazitaet( short lk );
protected:
    //Attribute:
	string name;
	double grundLaufzeit;
	short lastFaktor;
	short lastKapazitaet;
	short eingaenge;
};
#endif

