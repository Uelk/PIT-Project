#include "LaufzeitAnalysator.h"
using namespace std;

LaufzeitAnalysator::LaufzeitAnalysator() {
}

LaufzeitAnalysator::~LaufzeitAnalysator() {
}

void LaufzeitAnalysator::setSchaltwerkElement ( SchaltwerkElement* Schalti ) {
	SWE = Schalti;
}

void LaufzeitAnalysator::setFaktoren(Faktoren* fakt){
        faktoren = fakt;
}

void LaufzeitAnalysator::berechneLaufzeitEinzelgatter() {
	GatterTyp* temporGatterTyp;
	ListenElement* temporLE;
	SchaltwerkElement* temporSWE;

	double tpdactual;
	double tpd0; // Grundlaufzeit aus der Bib-Datei
    double tlast;	

	//Faktoren initialisieren
	double spgFaktor;
	double przFaktor;
	double tmpFaktor;
	//Werte der Faktoren erfragen
	spgFaktor = faktoren->getProzess();
	tmpFaktor = faktoren->getSpannung();
	przFaktor = faktoren->getTemperatur();
	
	do{
		temporSWE = temporLE->getSchaltwerkElement();
		temporGatterTyp = temporSWE->getTyp();
		tpd0 = temporGatterTyp->getGrundLaufzeit(); //Erfragen der Grundlaufzeit aus der Bib
		tlast = 0; //Reset von tlast

		for (int i = 0; i < ( temporLE->getSchaltwerkElement()->getAnzahlNachfolger()); i++){
			tlast += temporSWE->getNachfolger(i)->getTyp()->getLastKapazitaet();
		}

		tlast = tlast * temporSWE->getTyp()->getLastFaktor() / 1000; //Umrechnung in Pikosekunden
		tpdactual = (tpd0 + tlast) *  przFaktor * tmpFaktor * spgFaktor ; //tpd,actual = (tpd0 + tlast) * KP * KT * KV
		temporSWE->setLaufzeitEinzelgatter(tpdactual);

	temporLE = temporLE->getNextElement();
	} while( temporLE != NULL );

	//tpdactual = (tpd0+ Kl*Clast) * Kt(tmpFaktor)*Kv(spgFaktor)*Kp(przFaktor))
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