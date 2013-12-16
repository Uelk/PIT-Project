#ifndef LAUFZEITANALYSATOR_H
#define LAUFZEITANALYSATOR_H

#include <iostream>
#include <map>
#include "ListenElement.h"
#include "SchaltwerkElement.h"
#include "GraphErzeuger.h"
#include "Faktoren.h"
#include "Bibliothek.h"
using namespace std;

class LaufzeitAnalysator {
private:
	Faktoren* faktoren;
	ListenElement* startElement;
	Bibliothek* bibliothek;
	struct DFS_Daten;
	map<SchaltwerkElement*, DFS_Daten> DFS_Zwischenspeicher;
	long frequenz;
	long maximaleFrequenz;
	string uebergangspfad;
	string ausgangspfad;
	double laufzeitUebergangspfad;
	double laufzeitAusgangspfad;
	void berechneLaufzeitEinzelgatter();
	void DFS( ListenElement* );
	void DFS_Visit( SchaltwerkElement*, SchaltwerkElement* );
	bool zyklensuche( SchaltwerkElement* );
	string generierePfadBesuchterGatter(SchaltwerkElement*, SchaltwerkElement*, SchaltwerkElement*);
	void berechnneMaximaleFrequenz();
	bool zyklusMerker;
public:
	LaufzeitAnalysator();
	~LaufzeitAnalysator();
	void starteAnalyse();
	void setFaktoren (Faktoren*);
	void setBibliothek(Bibliothek*);
	void setStartElement(ListenElement*);
	void setFrequenz( long );
	void ausgabeErgebnis();
};
#endif