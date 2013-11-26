// Menue.cpp
// Informationstechnik Praktikum WS 13/14
//
// Created by Benedikt, Marius and Joshua

#include <iostream>
#include "Menue.h"
#include "Faktoren.h"
#include "Bibliothek.h"
#include "SignalListeErzeuger.h"
//#include "GraphErzeuger.h"
//#include "LaufzeitAnalysator.h"

using namespace std;

Menue::Menue() {
	meineFaktoren = new Faktoren();
	meineBibliothek = new Bibliothek();
	meinSignalListeErzeuger = new SignalListeErzeuger();
    //meinGraphErzeuger = new GraohErzeugers();
    //meinLaufzeitAnalysator = new LaufzeitAnalysator();
}

Menue::~Menue () {
}

void Menue::start() {
	menueKopf ();
	int menueEingabe;
	while (true) {
		cin >> menueEingabe;
		switch (menueEingabe) {
			case 1:
				faktorenMenue();
                menueKopf ();
				break;
			case 2:
				bibliothekMenue();
				menueKopf ();
				break;
			case 3:
				schaltwerkMenue();
				menueKopf ();
				break;
			case 4:
				analyse();
				break;
			case 5:
				exit(1);
				break;
			default:
				cout << endl << "Ungueltige Eingabe!" << endl;
				break;
		}
	}
}

void Menue::faktorenMenue () {
	system("cls");
	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl;
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cout << "Untermenue Aussere Faktoren" << endl;
	cout << "(1) Spannung [Volt]: " << meineFaktoren->getSpannung() << endl;
	cout << "(2) Temperatur [Grad Celsius]: " << meineFaktoren->getTemperatur() << endl;
	cout << "(3) Prozess (1=slow, 2=typical; 3=fast): " << meineFaktoren->getProzess() << endl;
	cout << "(4) Ausgabe errechneter Faktoren" << endl;
	cout << endl;
	cout << "(5) Hauptmenue" << endl;
	cout << endl;
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";

	int menueEingabe;
	cin >> menueEingabe;

	switch(menueEingabe) {
	case 1:
		double spannung;
		cout << "Geben Sie den neuen Spannungswert ein: ";
		cin >> spannung;
		meineFaktoren->setSpannung(spannung);
		faktorenMenue();
		break;
	case 2:
		double temperatur;
		cout << "Geben Sie einen neuen Temperaturwert ein: ";
		cin >> temperatur;
		meineFaktoren->setTemperatur(temperatur);
		faktorenMenue();
		break;
	case 3:
		short prozess;
		cout << "Geben Sie einen neuen Prozesstyp ein: ";
		cin >> prozess;
		if(prozess == 1 || prozess == 2 || prozess == 3) {
			meineFaktoren->setProzess(prozess);
		} else {
			cerr << "Ungueltige Eingabe!" << endl;
			system("pause");
		}
		faktorenMenue();
		break;
	case 4:
		meineFaktoren->ausgabeFaktoren();
		system("pause");
		break;
	case 5:
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		break;
	}
}

void Menue::bibliothekMenue() {
	system("cls");
	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl;
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cout << "Untermenue Bibliothek" << endl;
	cout << "(1) Pfad zur Bibliotheksdatei: " << meineBibliothek->getPfad() << endl;
	cout << "(2) Ausgabe der Bibliotheksdatei" << endl;
	cout << "(3) Hauptmenue" << endl;
	cout << endl;
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";

	int menueEingabe;
	string dateiPfad;
	cin >> menueEingabe;

	switch(menueEingabe) {
	case 1:
		cout << "Geben Sie einen neuen Dateipfad an! (Einfache '\\' mit '\\\\' ersetzen!):" << endl;
		cin >> dateiPfad;
		if(!meineBibliothek->pfadEinlesen(dateiPfad)) {
			cout << "Ungueltiger Dateipfad" << endl;

			system("pause");
		}

		bibliothekMenue();
		break;
	case 2:
		meineBibliothek->dateiAusgabe();
		meineBibliothek->openError();
		meineBibliothek->readError();
		system("pause");
		bibliothekMenue();
		break;
	case 3:
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		bibliothekMenue();
		break;
	}
}

void Menue::schaltwerkMenue() {
	system("cls");
	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl;
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cout << "Untermenue Schaltwerk" << endl;
	cout << "(1) Pfad zur Schaltnetzdatei: " << meinSignalListeErzeuger->getDateiPfad() << endl;
	cout << "(2) Ausgabe der Schaltnetzdatei" << endl;
	cout << "(3) Ausgabe der Signale" << endl;
	cout << "(4) Ausgabe der Graphstruktur" << endl;
	cout << "(5) Hauptmenue" << endl;
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";

	int menueEingabe;
	cin >> menueEingabe;

	switch (menueEingabe) {
	case 1:
		meinSignalListeErzeuger->getDateiPfad();
		break;
	case 2:
		meinSignalListeErzeuger->ausgabeDatei();
		break;
	case 3:
		meinSignalListeErzeuger->ausgabeDatei();
		break;
	case 4:
		cout << "Graphenstruktur: " << endl;
		cout << "----------------" << endl;
		cout << "Gattername: " /*<< meinGraphErzeuger->getName()*/ << endl;
		cout << "Gattertyp: " /*<< meinGraphErzeuger->getTyp()*/ << endl;
		cout << "--> Das Gatter hat " /*<< meinGraphErzeuger->getAnzahlNachfolger()*/ << " Zeile" << endl;
		cout << "Angeschlossene Gatter: " /*<< meinGraphErzeuger->getNachfolger()*/ << endl;
		break;
	case 5:
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		break;
	}
}

void Menue::analyse() {
	cout << "Analyse: " << endl;
	cout << "--------" << endl;
	cout << "Laengster Pfad im Ueberfuehrungsschaltnetz: " << endl;
	/* add Algorithmus */
	cout << "Maximale Laufzeit der Pfade im Ueberfuehrungsschaltnetz: " /*<<  add Algorithmus */ << " ps" << endl;
	cout << endl;
	cout << "Laengster Pfad im Ausgangsschaltnetz: " << endl;
	/* add Algorithmus */
	cout << "Maximale Laufzeit der Pfade im Ausgangsschaltnetz: " /* add Algorithmus */ << " ps" << endl;
	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "Die maximal zulaessige Frequenz fuer das Schaltnetz/-werk betraegt: " /*<< add Algorithmus */ << " MHz" << endl;
	cout << endl;
/*
if ( algorithmusVariable >= maxFrequenz ) {
	cout << "Die Bedingung fuer die Taktfrequenz vom Schaltnetz/-werk ist nicht erfüllt!" << endl;
	cout << "Die Taktfrequenz " << frequenzVariable << " ist groesser als die maximale Frequenz!" << endl;
} else {
	cout << "Die Bedingung fuer die Taktfrequenz vom Schaltnetz/-werk ist erfüllt!" << endl;
}

*/
}

void Menue::menueKopf() {
	system("cls");
	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl;
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cout << "(1) Aeussere Faktoren" << endl;
	cout << "Spannung [Volt]: " << meineFaktoren->getSpannung() << endl;
	cout << "Temperatur [Grad Celsius]: " << meineFaktoren->getTemperatur() << endl;
	cout << "Prozess (1=slow, 2=typical, 3=fast): " << meineFaktoren->getProzess() << endl;
	cout << endl;
	cout << "(2) Bibliothek" << endl;
	cout << "Pfad zur Bibliotheksdatei: " << meineBibliothek->getPfad() << endl;
	cout << endl;
	cout << "(3) Schaltwerk" << endl;
	cout << "Pfad zur Schaltwerksdatei: " << endl;
	cout << endl;
	cout << "(4) Analyse starten" << endl;
	cout << endl;
	cout << "(5) Programm beenden" << endl;
	cout << endl;
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
}