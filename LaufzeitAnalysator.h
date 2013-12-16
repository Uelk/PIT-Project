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
	struct DFS_Daten;
	map<SchaltwerkElement*, DFS_Daten> DFS_Zwischenspeicher;
	long frequenz;
	string uebergangspfad;
	string ausgangspfad;
	double laufzeitUebergangspfad;
	double laufzeitAusgangspfad;
	void berechneLaufzeitEinzelgatter();
	void DFS(ListenElement*);
	void DFS_Visit();
public:
	LaufzeitAnalysator();
	~LaufzeitAnalysator();
	void starteAnalyse();
	void setFaktoren (Faktoren*);
	void setStartElement(ListenElement*);
	void setFrequenz(long);
	void ausgabeErgebnis();
};
#endif