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
	laufzeitUebergangspfad = 0;
	uebergangspfad = "";
	laufzeitAusgangspfad = 0;
	ausgangspfad = "";
	zyklusMerker = false;

	// Komplette Graph Liste durchlaufen
	for( ListenElement* temporLE = startElement; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		// Startknoten finden und Tiefensuche von dort beginnen
		// gueltige Startknoten sind Eingangselemente oder Flip-Flops
		if( temporLE->getSchaltwerkElement()->getIsEingangsElement || temporLE->getSchaltwerkElement()->getTyp()->getIsFlipFlop ) {
			DFS( temporLE );
		}
	}

	// Abbruch der Analyse bei existierendem Zyklus
	if( zyklusMerker ) {
		return;
	}

	berechnneMaximaleFrequenz();
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

// Funktion zum Start einer Tiefensuche mit gegebenem Startknoten
void LaufzeitAnalysator::DFS( ListenElement* startKnoten ) {
	for( ListenElement* temporLE = startKnoten; temporLE != NULL; temporLE = temporLE->getNextElement() ) {
		DFS_Zwischenspeicher[temporLE->getSchaltwerkElement()].PfadLaufzeit = 0;
		DFS_Zwischenspeicher[temporLE->getSchaltwerkElement()].VaterElement = NULL;
	}

	DFS_Visit( startKnoten->getSchaltwerkElement(), startKnoten->getSchaltwerkElement() );
}

// Funktion der Tiefensuche
void LaufzeitAnalysator::DFS_Visit( SchaltwerkElement* k, SchaltwerkElement* s ) {
	SchaltwerkElement* v;
	for( int i = 0; i < k->getAnzahlNachfolger(); i++ ) {
		v = k->getNachfolger(i);
		
		if( v->getTyp()->getIsFlipFlop() ) {
			if( laufzeitUebergangspfad < DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter() ) {
				laufzeitUebergangspfad = DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter();
				uebergangspfad = generierePfadBesuchterGatter( s, k, v );
			}
		} else {
			if( DFS_Zwischenspeicher[v].PfadLaufzeit < DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter() ) {
				if( DFS_Zwischenspeicher[v].PfadLaufzeit != 0 || v == s ) {
					DFS_Zwischenspeicher[v].VaterElement = k;
					if( zyklensuche( v ) ) {
						cout << "Zyklus an Gatter gefunden: " << v->getName() << endl;
						system( "pause" );
						break;
					}
				}
				DFS_Zwischenspeicher[v].PfadLaufzeit = DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter();
				DFS_Zwischenspeicher[v].VaterElement = k;
				DFS_Visit(v, s);
			}
		}

		if( k->getIsAusgangsElement() && laufzeitAusgangspfad < DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter() ) {
			laufzeitAusgangspfad = DFS_Zwischenspeicher[k].PfadLaufzeit + k->getLaufzeitEinzelgatter();
			ausgangspfad = generierePfadBesuchterGatter( s, k, v );
		}
	}
}

// Ueberprueft, ob ein Zyklus an einem SchaltwerkElement vorliegt
bool LaufzeitAnalysator::zyklensuche( SchaltwerkElement* schaltwerkElement ) {
	SchaltwerkElement* temp = schaltwerkElement;
	// alle Vaterelemente untersuchen
	for( SchaltwerkElement* temp = schaltwerkElement; temp != NULL; DFS_Zwischenspeicher[temp].VaterElement) {
		// aktuelles Element ist sein eigener Vorgaenger, so folgt vorhandener Zyklus
		if( temp == schaltwerkElement ) {
			zyklusMerker = true;
			return true;
		}
	}
	return false;
}

// erstellt den String der besuchten Gatter
string LaufzeitAnalysator::generierePfadBesuchterGatter(SchaltwerkElement* s, SchaltwerkElement* k, SchaltwerkElement* v) {
	string pfad = "";
	// Folgeknoten eintragen falls vorhanden
	if(v != NULL) {
		pfad = v->getName();
		pfad = "->" + pfad;
	}
	pfad = pfad + k->getName(); // aktuellen Knoten eintragen
	pfad = "->" + pfad;
	// Vorgaenger-Knoten eintragen
	for( SchaltwerkElement* temporSW = k; temporSW != s; temporSW = DFS_Zwischenspeicher[temporSW].VaterElement) {
		pfad = temporSW->getName();
		pfad = "->" + pfad;
	}
	pfad = pfad + s->getName(); // Startknoten eintragen
	return pfad;
}

void LaufzeitAnalysator::berechnneMaximaleFrequenz() {
	double setupTime = ( (FlipFlop*) bib->getBibElement("dff") )->getSetupTime();
}

void LaufzeitAnalysator::ausgabeErgebnis() {
	cout << "Laengster Pfad im Ueberfuehrungsschaltnetz:" << endl;
	cout << uebergangspfad << endl;
	cout << "Maximale Laufzeit der Pfade im Ueberfuehrungsschaltnetz: ";
	cout << laufzeitUebergangspfad << " ps" << endl;
	cout << "Laengster Pfad im Ausgangsschaltnetz:" << endl;
	cout << ausgangspfad << endl;
	cout << "Maximale Laufzeit der Pfade im Ausgangsschaltnetz: ";
	cout << laufzeitAusgangspfad << endl;
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
	cout << "Die maximal zulaessige Frequenz fuer das Schaltnetz/-werk betraegt: ";
	cout << endl;
	cout << "-----------------------------------" << endl;
}