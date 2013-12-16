#include "LaufzeitAnalysator.h"
using namespace std;

LaufzeitAnalysator::LaufzeitAnalysator() {
}

LaufzeitAnalysator::~LaufzeitAnalysator() {
}

struct LaufzeitAnalysator::DFS_Daten {
	SchaltwerkElement* VaterElement;
	double PfadLaufzeit;
};

void LaufzeitAnalysator::starteAnalyse() {
	berechneLaufzeitEinzelgatter();

}

void LaufzeitAnalysator::setFaktoren(Faktoren* fakt){
        faktoren = fakt;
}

void LaufzeitAnalysator::setStartElement(ListenElement* start) {
	startElement = start;
}

void LaufzeitAnalysator::setFrequenz( long f ) {
	frequenz = f;
}

void LaufzeitAnalysator::berechneLaufzeitEinzelgatter() {
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		GatterTyp* gatterTyp = temporLE->getSchaltwerkElement()->getTyp();
		double tpd = gatterTyp->getGrundLaufzeit();
		double kl = gatterTyp->getLastFaktor();
		double c_last = gatterTyp->getLastKapazitaet();
		double kt = faktoren->getTemperaturFaktor();
		double kv = faktoren->getSpannungFaktor();
		double kp = faktoren->getProzessFaktor();
		temporLE->getSchaltwerkElement()->setLaufzeitEinzelgatter( ( tpd + kl + c_last ) * kt * kv * kp );
	}
}

void LaufzeitAnalysator::DFS(ListenElement* start) {

}

void LaufzeitAnalysator::DFS_Visit() {
	
}

void LaufzeitAnalysator::ausgabeErgebnis() {
	cout << "Laengster Pfad im Ueberfuehrungsschaltnetz:" << endl;
	cout << "Maximale Laufzeit der Pfade im Ueberfuehrungsschaltnetz: ";
	cout << endl;
	cout << "Laengster Pfad im Ausgangsschaltnetz:" << endl;
	cout << "Maximale Laufzeit der Pfade im Ausgangsschaltnetz: ";
	cout << endl;
	cout << "-----------------------------------";
	cout << "Die maximal zulaessige Frequenz fuer das Schaltnetz/-werk betraegt: ";
	cout << endl;
	cout << "-----------------------------------";
}