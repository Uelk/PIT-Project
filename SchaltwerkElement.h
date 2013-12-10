#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H

#include <string>
#include "GatterTyp.h"
using namespace std;

class SchaltwerkElement {
private:
	string name;
	GatterTyp* typ;
	double LaufzeitEinzelgatter;
	SchaltwerkElement* nachfolgerElemente[5];
	int anzahlNachfolger;
	bool isEingangsElement;
	bool isAusgangsElement;
	short anzahlEingangssignale;
public:
	SchaltwerkElement( void );
	~SchaltwerkElement( void );
	SchaltwerkElement( GatterTyp* gTyp );
	string getName();
	GatterTyp* getTyp();
	double getLaufzeitEinzelgatter();
	SchaltwerkElement* getNachfolger( int pos );
	int getAnzahlNachfolger();
	short getAnzahlEingangssignale();
	bool getIsEingangsElement();
	bool getIsAusgangsElement();
	void setName( string n );
	void nachfolgerHinzufuegen( SchaltwerkElement* schaltwerkElement, int pos );
	void setAnzahlNachfolger( int anzahlN );
	void setAnzahlEingangssignale( short anzahlE );
	void setIsEingangsElement( bool isEingangsEl );
	void setIsAusgangsElement( bool isAusgangsEl );
	void setLaufzeitEinzelgatter( double lfz );
};
#endif