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
	SchaltwerkElement( GatterTyp* );
	string getName();
	GatterTyp* getTyp();
	double getLaufzeitEinzelgatter();
	SchaltwerkElement* getNachfolger( int );
	int getAnzahlNachfolger();
	short getAnzahlEingangssignale();
	bool getIsEingangsElement();
	bool getIsAusgangsElement();
	void setName( string n );
	void nachfolgerHinzufuegen( SchaltwerkElement*, int );
	void setAnzahlNachfolger( int anzahlN );
	void setAnzahlEingangssignale( short );
	void setIsEingangsElement( bool );
	void setIsAusgangsElement( bool );
	void setLaufzeitEinzelgatter( double );
};
#endif