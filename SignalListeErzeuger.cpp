#include "SignalListeErzeuger.h"
using namespace std;

// Datei auslesen; Leseschnittpunkte festlegen
void SignalListeErzeuger::dateiAuslesen() {
	anzahlSignale = 0;
	ifstream file( datei );
	while( getline( file, line )) {
		if( line.find( "INPUT" ) != -1 ) {
			inputsAuslesen();
		}
		if( line.find( "OUTPUT" ) != -1 ) {
			outputsAuslesen();
		}
		if( line.find( "SIGNALS" ) != -1 ) {
			signalsAuslesen();
		}
		if( line.find( "CLOCK" ) != -1 ) {
			clockAuslesen();
		}
		if( line.find( "BEGIN" ) != -1 ) {
			signale = new Signal[anzahlSignale];
			signalTypenErkennung();
			getline( file, line );
			while( line.find( "END" ) == -1 ) {
				schaltnetzwerkBeschreibungAuslesen();
				getline( file, line );
			}
		}
	}
	file.close();
}

// Rueckgabe Anzahl Signale
int SignalListeErzeuger::getAnzahlSignale() {
	return anzahlSignale;
}

// Inputsignale auswerten
void SignalListeErzeuger::inputsAuslesen() {
	line = line.substr( 6 );
	input = line.substr( 0, line.find( ';' ) );
	
	for( int i = 0; i < input.length(); i++ ) {
		if( input.at( i ) == 's' ) {
			anzahlSignale++;
		}
	}
}

// Outputsignale auswerten
void SignalListeErzeuger::outputsAuslesen() {
	line = line.substr( 7 );
	output = line.substr( 0, line.find( ';' ));
	for( int i = 0 ; i < output.length() ; i++ ) {
		if( output.at( i ) == 's' ) {
			anzahlSignale++;
		}
	}
}

// Signale auswerten
void SignalListeErzeuger::signalsAuslesen() {
	line = line.substr( 8 );
	signals = line.substr( 0, line.find( ';' ));
	for( int i = 0 ; i < signals.length() ; i++ ) {
		if( signals.at( i ) == 's' ) {
			anzahlSignale++;
		}
	}
}

// Frequenz auswerten
void SignalListeErzeuger::clockAuslesen() {
	anzahlSignale++;
	line = line.substr( 6 );
	int pos = line.find( ',' );
	clockName = line.substr( 0, pos );
	line = line.substr( pos + 2 );
	pos = line.find( ' ' );
	frequenz = atof( line.substr( 0, pos ).c_str());
	line = line.substr( pos + 1 );
	pos = line.find( ';' );
	line = line.substr( pos );
	if( line.find( "MHz" ) != -1 ) {
		frequenz *= 1000000;
	}
	if( line.find( "kHz" ) != -1 ) {
		frequenz *= 1000;
	}
}

// Bestimmung der Signaltypen
void SignalListeErzeuger::signalTypenErkennung() {
	string name;
	signale[0].setSignalTyp( signale[0].unbekannt );
	for( int i = 1; i < anzahlSignale; i++ ) {
		name = 's' + to_string(i);
		if( name.length() < 4 ) {
			name = name.insert( 1, 4 - name.length(), '0' );
		}
		if( isInput( name )) {
			signale[i].setSignalTyp( signale[i].eingang );
		}
		if( isSignal( name )) {
			signale[i].setSignalTyp( signale[i].intern );
		}
		if( isOutput( name )) {
			signale[i].setSignalTyp( signale[i].ausgang );
		}
	}
};

// Schaltnetzwerk auswerten
void SignalListeErzeuger::schaltnetzwerkBeschreibungAuslesen() {
	line = line.substr( 0, line.find( ';' ) - 1 );
	string gatterName = line.substr( 0, 4 ); // Gatter bestimmen
	line = line.substr( 5 );
	string GatterTyp = line.substr( 0, line.find( '(' )); // GatterTyp bestimmen
	line = line.substr( line.find( '(' ) + 1 );
	string ausgangName = line.substr( line.find_last_of( ',' ) + 1 ); // Outputsignal finden
	line = line.substr( 0, line.find_last_of( ',' ) );
	int signalNummer = atoi( ausgangName.substr( 1, 3 ).c_str());
	signale[signalNummer].setQuelle( gatterName ); // Quelle festlegen
	signale[signalNummer].setQuellenTyp( GatterTyp ); // Quellentyp festlegen
	while( line.find( ',' ) != -1 ) { // Eingangssignale abarbeiten
		if( line.substr( 0, line.find( ',' )).find( clockName ) != -1 ) {
			signale[0].zielHinzufuegen( gatterName, signale[0].getAnzahlZiele() );
			signale[0].setAnzahlZiele( signale[0].getAnzahlZiele() + 1 );
			line = line.substr( line.find( ',' ) + 1 );
		} else {
			signalNummer = atoi( line.substr( 1, 3 ).c_str());
			signale[signalNummer].zielHinzufuegen( gatterName, signale[signalNummer].getAnzahlZiele());
			signale[signalNummer].setAnzahlZiele( signale[signalNummer].getAnzahlZiele() + 1 );
			line = line.substr( 5 );
		}
	}
    // Speichern des letzten Eingangssignals
	if( line.find( clockName ) != -1 ) {
		signale[0].zielHinzufuegen( gatterName, signale[0].getAnzahlZiele() );
		signale[0].setAnzahlZiele( signale[0].getAnzahlZiele() + 1 );
	} else {
		signalNummer = atoi( line.substr( 1, 3 ).c_str() );
		signale[signalNummer].zielHinzufuegen( gatterName, signale[signalNummer].getAnzahlZiele());
		signale[signalNummer].setAnzahlZiele( signale[signalNummer].getAnzahlZiele() + 1 );
	}
}

// Inputsignal vorhanden?
bool SignalListeErzeuger::isInput( string signal ) {
	if( input.find( signal ) != -1 ) {
		return true;
	}
	return false;
}

// Outputsignal vorhanden?
bool SignalListeErzeuger::isOutput( string signal ) {
	if( output.find( signal ) != -1 ) {
		return true;
	}
	return false;
}

// Signal vorhanden?
bool SignalListeErzeuger::isSignal( string signal ) {
	if( signals.find( signal ) != -1 ) {
		return true;
	}
	return false;
}

// Ueberpruefen, ob Dateiauslesen moeglich
bool SignalListeErzeuger::setDateiPfad( string pfad ) {
	ifstream file( pfad );
	if( !file.fail()) {
		datei = pfad;
		dateiAuslesen();
		return true;
	} else {
		return false;
	}
	file.close();
}

// Datei zurueckgeben
string SignalListeErzeuger::getDateiPfad() {
	return datei;
}

// Datei ausgeben
void SignalListeErzeuger::ausgabeDatei() {
	string zeile;
	int i = 0;
	ifstream file( datei );
	while( getline( file, zeile )) {
		i++;
		cout << i << ' ' << zeile << endl;
	}
	file.close();
}

Signal* SignalListeErzeuger::getSignalListe() {
	return signale;
}

// Ausgabe der Signalauswertung in der Konsole
void SignalListeErzeuger::ausgabeSignale() {
	cout << "Signale: " << endl;
	cout << "--------" << endl;
	cout << "Signalname: " << clockName << endl;
	cout << "Signaltyp: Unbekannt" << endl;
	cout << "Signalquelle: keine" << endl;
	cout << "--> DasSignal hat " << signale[0].getAnzahlZiele() << " Ziele" << endl;
	cout << "Ziel-Gatter: ";
	for( int i = 0; i < signale[0].getAnzahlZiele(); i++ ) {
		cout << signale[0].getZiel(i) << " ";
	}
	cout << endl;
	cout << "--------" << endl;

	string name;
	for( int i = 1; i < anzahlSignale; i++ ) {
		name = 's' + to_string(i);
		if( name.length() < 4 ) {
			name = name.insert( 1, 4 - name.length(), '0' );
		}
		cout << "Signalname: " << name << endl;
		cout << "Signaltyp: ";
		int typ = signale[i].getSignalTyp();
		switch(typ) {
		case 0:
			cout << "Eingang";
			break;
		case 1:
			cout << "Intern";
			break;
		case 2:
			cout << "Ausgang";
			break;
		case 3:
			cout << "Unbekannt";
			break;
		}
		cout << endl;
		cout << "Signaltyp: " << signale[i].getSignalTyp() << endl;
		cout << "Signalquelle: ";
		if( signale[i].getQuelle().length() == 0) {
			cout << "keine";
		} else {
			cout << signale[i].getQuelle();
		}
		cout << endl;
		cout << "->Das Signal hat " << signale[i].getAnzahlZiele() << " Ziele" << endl;
		cout << "Ziel-Gatter: "; 
		for( int j = 0; j < signale[i].getAnzahlZiele(); j++ ) {
			cout << signale[i].getZiel(j) << " ";
		}
		cout << endl;
		cout << "--------" << endl;
	}
}