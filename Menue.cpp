#include <iostream>
#include "Menue.h"
#include "Faktoren.h"
#include "Bibliothek.h"
#include "SignalListeErzeuger.h"
#include "GraphErzeuger.h"
#include "LaufzeitAnalysator.h"

using namespace std;

Menue::Menue() {
	meineFaktoren = new Faktoren();
	meineBibliothek = new Bibliothek();
	meinSignalListeErzeuger = new SignalListeErzeuger();
	meinGraphErzeuger = new GraphErzeuger();
    meinLaufzeitAnalysator = new LaufzeitAnalysator();
}

Menue::~Menue () {
}

// Ausgabe des Hauptmenues
void Menue::menueKopf() {
	system( "cls" );
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

// Auswahl Untermenue
void Menue::start() {
	menueKopf ();
	int menueEingabe = 0;
	string input;

	while (true) {
		cin >> input;
		menueEingabe= atoi(input.c_str()); 
		if( menueEingabe ){
			switch ( menueEingabe ) {
				case 1:
					faktorenMenue();
					menueKopf();
					break;
				case 2:
					bibliothekMenue();
					menueKopf();
					break;
				case 3:
					schaltwerkMenue();
					menueKopf();
					break;
				case 4:
					meinLaufzeitAnalysator->setFaktoren( meineFaktoren );
					meinLaufzeitAnalysator->starteAnalyse();
					meinLaufzeitAnalysator->ausgabeErgebnis();
					system( "pause" );
					menueKopf();
					break;
				case 5:
					exit(1);
					break;
				default:
					cout << endl << "Ungueltige Eingabe!" << endl;
					system( "pause" );
					break;
			}
		} else {
			cout << endl << "Ungueltige Eingabe!" << endl;
			system( "pause" );
			menueKopf();
		}
	}
}

// Ausgabe Untermenue Aeussere Faktoren
void Menue::faktorenMenue () {
	system( "cls" );
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
	
	int menueEingabe = 0;
	string input;
    string inputWert;
	cin >> input;
	menueEingabe= atoi( input.c_str() ); 

	if(menueEingabe){
		switch(menueEingabe) {
		case 1:
			// Spannung festlegen
			double spannung;
			cout << "Geben Sie einen neuen Spannungswert ein: ";
			cin >> inputWert;
			if ( isDouble( inputWert ) )
			{
				spannung = atof( inputWert.c_str() );
				meineFaktoren->setSpannung( spannung );
			} else {
				cout << endl << "Ungueltige Eingabe!" << endl;
				system( "pause" );
			}
			faktorenMenue();
			break;
		case 2:
		    // Temperatur festlegen
			double temperatur;
			cout << "Geben Sie einen neuen Temperaturwert ein: ";
			cin >> inputWert;
			if ( isDouble( inputWert ) ) {
				temperatur = atof( inputWert.c_str() );
				meineFaktoren->setTemperatur( temperatur );
			} else {
				cout << endl << "Ungueltige Eingabe!" << endl;
				system( "pause" );
			}
			faktorenMenue();
			break;
		case 3:
		   // Prozesstyp festlegen
			short prozess;
			cout << "Geben Sie einen neuen Prozesstyp ein: ";
			cin >> prozess;
			if( prozess == 1 || prozess == 2 || prozess == 3 ) {
				meineFaktoren->setProzess( prozess );
			} else {
				cerr << "Ungueltige Eingabe!" << endl;
				system( "pause" );
			}
			faktorenMenue();
			break;
		case 4:
			// Ausgabe errechneter Faktoren
			meineFaktoren->ausgabeFaktoren();
			system( "pause" );
			faktorenMenue();
			break;
		case 5:
			// zurueck zum Hauptmenue
			break;
		default:
			cout << endl << "Ungueltige Eingabe!" << endl;
			system( "pause" );
			break;
		}
	} else {
		cout << endl << "Ungueltige Eingabe!" << endl;
		system( "pause" );
		faktorenMenue();
	}
}

// Ausgabe Untermenue Bibliothek
void Menue::bibliothekMenue() {
	system( "cls" );
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
	
	string dateiPfad;
	int menueEingabe = 0;
	string input;
	cin >> input;
	menueEingabe= atoi( input.c_str() );

	if(menueEingabe) {
		switch(menueEingabe) {
			case 1:
				// Eingabe Dateipfad
				cout << "Geben Sie einen neuen Dateipfad an:" << endl;
				cin >> dateiPfad;
				if( !meineBibliothek->pfadEinlesen( dateiPfad )) {
					cout << "Ungueltiger Dateipfad" << endl;
					system( "pause" );
				}
				bibliothekMenue();
				break;
			case 2:
			  // Anzeigen der Bibliothekdatei
				meineBibliothek->dateiAusgabe();
				meineBibliothek->dateiAuswerten();
				meineBibliothek->openError();
				meineBibliothek->readError();
				system( "pause" );
				bibliothekMenue();
				break;
			case 3:
			   // zurueck zum Hauptmenue
				break;
			default:
				cout << endl << "Ungueltige Eingabe!" << endl;
				system( "pause" );
				bibliothekMenue();
				break;
			}
	} else {
		cout << endl << "Ungueltige Eingabe!" << endl;
		system( "pause" );
		bibliothekMenue();
	}
}


// Ausgabe Untermenue Schaltwerkmenue
void Menue::schaltwerkMenue() {
	system( "cls" );
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

	string dateiPfad;
	int menueEingabe=0;
	string input;

	cin >> input;
	menueEingabe= atoi(input.c_str());

	if( menueEingabe ){
		switch( menueEingabe ) {
			case 1:
			  // Eingabe Dateipfad
				cout << "Geben Sie einen neuen Dateipfad an:" << endl;
				cin >> dateiPfad;
				if( !meinSignalListeErzeuger->setDateiPfad( dateiPfad ) ) {
					cout << "Ungueltiger Dateipfad" << endl;
					system( "pause" );
				} else {
					//Bei erfolgreicher Signallisten-Erzeugung Graphen generieren
					meinGraphErzeuger->setBibliothek( meineBibliothek );
					meinGraphErzeuger->setSignale( meinSignalListeErzeuger->getSignalListe(), meinSignalListeErzeuger->getAnzahlSignale() );
					meinGraphErzeuger->erzeugeGraph();
				}
				schaltwerkMenue();
				break;
			case 2:
			    // Anzeigen der Schaltwerkdatei
				cout << endl;
				cout << "Dateiausgabe:" << endl;
				cout << endl;
				meinSignalListeErzeuger->ausgabeDatei();
				system( "pause" );
				schaltwerkMenue();
				break;
			case 3:
			   // Ausgabe Signale
				meinSignalListeErzeuger->ausgabeSignale();
				system( "pause" );
				schaltwerkMenue();
				break;
			case 4:
				// Ausgabe Graphenstruktur
				meinGraphErzeuger->ausgabeGraph();
				system( "pause" );
				schaltwerkMenue();
				break;
			case 5:
			   // zurueck zum Hauptmenue
				break;
			default:
				cout << endl << "Ungueltige Eingabe!" << endl;
				system( "pause" );
				break;
		}
	} else {
		cout << endl << "Ungueltige Eingabe!" << endl;
		system( "pause" );
		schaltwerkMenue();
	}
}

bool Menue::isDouble(string s) {
	return true;
}