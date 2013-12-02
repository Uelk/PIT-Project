#ifndef SIGNAL_H
#define SIGNAL_H

#include <string>
using namespace std;

class Signal {
private:
	string quelle;
	string quellenTyp;
	string ziele [5];
	int anzahlZiele;
public:
	Signal();
	~Signal();
	static enum signalTypen { eingang, intern, ausgang, unbekannt };
	signalTypen signalTyp;
	signalTypen getSignalTyp();
	int getAnzahlZiele();
	string getQuelle();
	string getQuellenTyp();
	string getZiel( int );
	void setAnzahlZiele( int );
	void setSignalTyp( signalTypen );
	void setQuelle( string );
	void setQuellenTyp( string );
	void zielHinzufuegen( string, int );
};
#endif