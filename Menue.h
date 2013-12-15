#ifndef MENUE_H
#define MENUE_H

#include "Faktoren.h"
#include "Bibliothek.h"
#include "SignalListeErzeuger.h"
#include "GraphErzeuger.h"
#include "LaufzeitAnalysator.h"
#include "helper.h"
using namespace std;

class Menue {
private:
	Faktoren* meineFaktoren;
	Bibliothek* meineBibliothek;
	SignalListeErzeuger* meinSignalListeErzeuger;
	GraphErzeuger* meinGraphErzeuger;
	LaufzeitAnalysator* meinLaufzeitAnalysator;
    void faktorenMenue();
	void bibliothekMenue();
	void schaltwerkMenue();
	void menueKopf();
public:
	Menue();
	~Menue();
	void start();
};
#endif