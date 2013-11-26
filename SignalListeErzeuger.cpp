#include "SignalListeErzeuger.h"
using namespace std;

void SignalListeErzeuger::dateiAuslesen() {
	anzahlSignale = 0;
	ifstream datei( "C:\\MK\\Dropbox\\IT Praktikum\\Praktikumspaket\\csd.txt" );
	while( getline( datei, line )) {
		if( line.find( "INPUT" )) {
			inputAuslesen();
		}
		if( line.find( "OUTPUT" )) {
			outputsAuslesen();
		}
		if( line.find( "SIGNALS" )) {
			signalsAuslesen();
		}
		if( line.find( "CLOCK" )) {
			clockAuslesen();
		}
		if( line.find( "BEGIN" )) {
			signale = new Signal[anzahlSignale];
			signalTypenErkennung();
			getline( datei, line );
			while( line.find( "END" ) != -1 ) {
				schaltnetzwerkBeschreibungAuslesen();
				getline( datei, line );
			}
		}
	}
	datei.close();
}

void SignalListeErzeuger::inputAuslesen() {
	line = line.substr( 6 );
	input = line.substr( 0, line.find( ';' ) - 1 );
	anzahlSignale++;
}

void SignalListeErzeuger::outputsAuslesen() {
	line = line.substr( 7 );
	output = line.substr( 0, line.find( ';' ) - 1 );
	anzahlSignale++;
	for( int i = 0 ; i < output.length() ; i++ ) {
		if( output.at( i ) == ',' ) {
			anzahlSignale++;
		}
	}
}

void SignalListeErzeuger::signalsAuslesen() {
	line = line.substr( 8 );
	signals = line.substr( 0, line.find( ';' ) - 1 );
	anzahlSignale++;
	for( int i = 0 ; i < signals.length() ; i++ ) {
		if( signals.at( i ) == ',' ) {
			anzahlSignale++;
		}
	}
}

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

void SignalListeErzeuger::signalTypenErkennung() {
	string name;
	signale[0].setSignalTyp( signale[0].eingang );
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

void SignalListeErzeuger::schaltnetzwerkBeschreibungAuslesen() {
	line = line.substr( 0, line.find( ';' ) - 1 );
	string gatterName = line.substr( 0, 4 );
	line = line.substr( 0, 5 );
	string gatterTyp = line.substr( 0, line.find( '(' ));
	line = line.substr( line.find( '(' ) + 1 );
	string ausgangName = line.substr( line.find_last_of( ',' ) + 1 );
	line = line.substr( line.find_last_of( ',' ));
	int signalNummer = atoi( ausgangName.substr( 1, 3 ).c_str());
	signale[signalNummer].setQuelle( gatterName );
	signale[signalNummer].setQuellenTyp( gatterTyp );
	while( line.find( ',' ) != -1 ) {
		signalNummer = atoi( line.substr( 0, line.find( ',' )).c_str());
		line = line.substr( line.find( ',' ));
		signale[signalNummer].zielHinzufuegen( gatterName, signale[signalNummer].getAnzahlZiele());
		signale[signalNummer].setAnzahlZiele( signale[signalNummer].getAnzahlZiele() + 1 );
	}
	signalNummer = atoi( line.c_str());
	signale[signalNummer].zielHinzufuegen( gatterName, signale[signalNummer].getAnzahlZiele());
	signale[signalNummer].setAnzahlZiele( signale[signalNummer].getAnzahlZiele() + 1 );
}

bool SignalListeErzeuger::isInput( string signal ) {
	if( input.find( signal ) != -1 ) {
		return true;
	}
	return false;
}

bool SignalListeErzeuger::isOutput( string signal ) {
	if( output.find( signal ) != -1 ) {
		return true;
	}
	return false;
}

bool SignalListeErzeuger::isSignal( string signal ) {
	if( signals.find( signal ) != -1 ) {
		return true;
	}
	return false;
}