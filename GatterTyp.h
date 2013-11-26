#ifndef GATTERTYP_H
#define GATTERTYP_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
using namespace std;

class Gattertyp {
public:
    Gattertyp(void);
    ~Gattertyp(void);
    
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

