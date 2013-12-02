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
    //meinGraphErzeuger = new GraphErzeuger();
    //meinLaufzeitAnalysator = new LaufzeitAnalysator();
}

Menue::~Menue () {
}

// Ausgabe des Hauptmen�s
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
	cout << "Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger->getDateiPfad() << endl;
	cout << endl;
	cout << "(4) Analyse starten" << endl;
	cout << endl;
	cout << "(5) Programm beenden" << endl;
	cout << endl;
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";
}

// Auswahl Untermen�
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

// Ausgabe Untermen� Aeussere Faktoren
void Menue::faktorenMenue () {
	system("cls");
	cout << "******************************************" << endl;
	cout << "*     IT-Projektpraktikum WS2013/2014    *" << endl;
	cout << "* Laufzeitanalyse synchroner Schaltwerke *" << endl;
	cout << "******************************************" << endl;
	cout << endl;
	cout << "Untermenue Aeussere Faktoren" << endl;
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
        // Spannung festlegen
		double spannung;
		cout << "Geben Sie den neuen Spannungswert ein: ";
		cin >> spannung;
		meineFaktoren->setSpannung(spannung);
		faktorenMenue();
		break;
	case 2:
        // Temperatur festlegen
		double temperatur;
		cout << "Geben Sie einen neuen Temperaturwert ein: ";
		cin >> temperatur;
		meineFaktoren->setTemperatur(temperatur);
		faktorenMenue();
		break;
	case 3:
        // Prozesstyp festlegen
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
        // Ausgabe errechneter Faktoren
		meineFaktoren->ausgabeFaktoren();
		system("pause");
		faktorenMenue();
		break;
	case 5:
        // zur�ck zum Hauptmen�
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		break;
	}
}

// Ausgabe Untermen� Bibliothek
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
        // Eingabe Dateipfad
		cout << "Geben Sie einen neuen Dateipfad an:" << endl;
		cin >> dateiPfad;
		if(!meineBibliothek->pfadEinlesen(dateiPfad)) {
			cout << "Ungueltiger Dateipfad" << endl;
			system("pause");
		}
		bibliothekMenue();
		break;
	case 2:
        // Anzeigen der Bibliothekdatei
		meineBibliothek->dateiAusgabe();
		meineBibliothek->openError();
		meineBibliothek->readError();
		system("pause");
		bibliothekMenue();
		break;
	case 3:
        // zur�ck zum Hauptmen�
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		bibliothekMenue();
		break;
	}
}

// Ausgabe Untermen� Schaltwerkmen�
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
	cout << endl;
	cout << "Waehle einen Menuepunkt und bestaetige mit Enter: ";

	int menueEingabe;
	string dateiPfad;
	cin >> menueEingabe;
	switch (menueEingabe) {
	case 1:
        // Eingabe Dateipfad
		cout << "Geben Sie einen neuen Dateipfad an:" << endl;
		cin >> dateiPfad;
		if( !meinSignalListeErzeuger->setDateiPfad( dateiPfad ) ) {
			cout << "Ungueltiger Dateipfad" << endl;
			system("pause");
		}
		schaltwerkMenue();
		break;
	case 2:
        // Anzeigen der Schaltwerkdatei
		cout << endl;
		cout << "Dateiausgabe:" << endl;
		cout << endl;
		meinSignalListeErzeuger->ausgabeDatei();
		system("pause");
		schaltwerkMenue();
		break;
	case 3:
        // Ausgabe Signale
		meinSignalListeErzeuger->ausgabeSignale();
		system("pause");
		schaltwerkMenue();
		break;
	case 4:
		// Ausgabe Graphenstruktur
		system("pause");
		schaltwerkMenue();
		break;
	case 5:
        // zur�ck zum Hauptmen�
		break;
	default:
		cout << endl << "Ungueltige Eingabe!" << endl;
		system("pause");
		break;
	}
}

// Ausgabe der Schaltwerkanalyse
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
	cout << "Die Bedingung fuer die Taktfrequenz vom Schaltnetz/-werk ist nicht erf�llt!" << endl;
	cout << "Die Taktfrequenz " << frequenzVariable << " ist groesser als die maximale Frequenz!" << endl;
} else {
	cout << "Die Bedingung fuer die Taktfrequenz vom Schaltnetz/-werk ist erf�llt!" << endl;
}

*/
}