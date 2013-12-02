#include "Bibliothek.h"

Bibliothek::Bibliothek( void ) {
    this->errFileNotFound = false;
    this->errFileRead = false;
    this->errElNotInVec = true;
}

Bibliothek::~Bibliothek( void ) {
   // remove();
}

// Pfad und Datei auslesen
string Bibliothek::getPfad() {
	return datei;
}

// Bib-Element auslesen
Gattertyp* Bibliothek::getBibElement( string typ ) {
    for( unsigned int i = 0; i < bibElemente.size() ; i++ ) {
		if(( bibElemente[i]->getName()).compare(typ) == 0 ) {
			this->errElNotInVec = false;
			return this->bibElemente[i] ;
		}
	}
	return NULL;
}

// Bib-Datei ausgeben
void Bibliothek::dateiAusgabe( void ) {
    string line;
    int i;
    ifstream infile( this->datei );
    if( infile.is_open()) {
        i = 1;
        while( getline ( infile, line )) {
            cout << "(" << i++ << ") " << line <<endl;
        }
        infile.close();
    } else {
        this->errFileNotFound = true;
    }
}

// Bib-Datei auswerten
void Bibliothek::dateiAuswerten( void ) {
    string line;
    char Bausteine[4096];
    char SWert[4096];
    short  IWert;
    string inifile = this->datei + ".ini";
    char* pToken;
    Gattertyp* gt;
    Flipflop* ff;
    
    ifstream infile( this->datei );
    ofstream outfile( inifile );
    if( infile.is_open() && outfile.is_open()) {
        // String zum Auswerten vorbereiten
        while( getline( infile, line )) {
            line = str_replace( "[[", "[", line );
            line = str_replace( "]]", "]", line );
            line = str_replace( ":", "=", line );
            outfile << line << endl;
        }
        infile.close();
        outfile.close();
        GetPrivateProfileSectionA( "Bausteine", Bausteine, 4096, inifile.c_str());
        //	cout << "Section Bausteine:" << endl;
	
    
	for(pToken = Bausteine; ( pToken != NULL ) && ( *pToken != '\0' ); pToken = NextToken( pToken )) {
      if( strcmp( pToken, "dff" ) == 0 )  /* Auswerten als FlipFlop */ {
		ff = new Flipflop();
		ff->setName( pToken );
	    IWert = GetPrivateProfileIntA( pToken, "ed", 0, inifile.c_str());
		ff->setEingaenge( IWert );
		IWert = GetPrivateProfileIntA( pToken, "tsetup", 0, inifile.c_str());
		ff->setSetupTime( IWert );
		IWert = GetPrivateProfileIntA( pToken, "thold", 0, inifile.c_str());
		ff->setHoldTime( IWert );
		IWert = GetPrivateProfileIntA( pToken, "cd", 0, inifile.c_str());
		ff->setLastKapazitaet( IWert );
	//	IWert = GetPrivateProfileIntA( pToken, "et", 0, inifile.c_str());
	//	ff->( IWert );
		GetPrivateProfileStringA( pToken, "tpdt", "nix", SWert, 4096, inifile.c_str());
		ff->setGrundLaufzeit( atof( SWert ));
		IWert = GetPrivateProfileIntA( pToken, "kl", 0, inifile.c_str());
		ff->setLastFaktor( IWert );
		IWert = GetPrivateProfileIntA( pToken, "ct", 0, inifile.c_str());
		ff->setLastKapazitaetClock( IWert );
		this->bibElemente.push_back(( Gattertyp* ) ff );
  //      cout << "Flipflop " << pToken << " ed=" << IWert << " tpx " << SWert << endl; // Do something with string
	  } else  /* Auswerten als Gatter */ {
		gt = new Gattertyp();
		gt->setName( pToken );
	    IWert = GetPrivateProfileIntA( pToken, "ei", 0, inifile.c_str());
		gt->setEingaenge( IWert );
	    GetPrivateProfileStringA( pToken, "tpd0", "nix", SWert, 4096, inifile.c_str());
		gt->setGrundLaufzeit( atof( SWert ));
		IWert = GetPrivateProfileIntA( pToken, "kl", 0, inifile.c_str());
		gt->setLastFaktor( IWert );
		IWert = GetPrivateProfileIntA( pToken, "cl", 0, inifile.c_str());
		gt->setLastKapazitaet( IWert );
		this->bibElemente.push_back( gt );
 //       cout << "Gatter " << pToken << " ei=" << IWert << " tpx " << SWert  << endl; // Do something with string
        }
    }
    } else {
        this->errFileRead = true;
    }
}

// Dateipfad einlesen
bool Bibliothek::pfadEinlesen( string pfad ) {
    ifstream infile( pfad );
    if( infile.is_open()) {
		datei = pfad;
	    return true;
       } else {
        return false;
    } 
    infile.close(); 

}

// Fehler beim Öffnen
void Bibliothek::openError( void ) {
	if( errFileNotFound ) {
		cout << endl  << "Beim Oeffnen der Datei ist ein Fehler aufgetreten" << endl;
		errFileNotFound = false;
	}
}

// Fehler beim Lesen
void Bibliothek::readError( void ) {
	if( errFileRead ) {
		cout << endl  << "Beim Lesen der Datei ist ein Fehler aufgetreten" << endl;
		errFileRead = false;
	}
}

// Fehler bei Vektorauswertung
bool Bibliothek::vecError( void ) {
	if( errElNotInVec ) {
		cout << endl << "Das gesuchte Element befindet sich nicht im Vector" << endl;
		errElNotInVec = true;
	}
	return this-> errElNotInVec;
}