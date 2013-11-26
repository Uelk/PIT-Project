#include "helper.h"

//  Hilfsfunktion: Ersetze String in string
//  search=zu ersetzende string
//  replace=string der eingesetzt werden soll
//  subject=string in dem ersetzt werden soll
string str_replace( const string& search, const string& replace, const string& subject ) /* String Replace Funktion */ {
    string str = subject;
    size_t pos = 0;
    while(( pos = str.find( search, pos )) != string::npos ) {
        str.replace( pos, search.length(), replace );
        pos += replace.length();
    }
    return str;
}

char * NextToken( char * pArg ) {
    // find next null with strchr and
    // point to the char beyond that.
    return strchr( pArg, '\0' ) + 1;  //search for char in string
}

/*
//Funktion zur Ermittlung der Gültigkeit des gefundenen Zeichens
bool CharIn(char ch,string Charset)
{
bool rc; //return code
  rc=false;
  if (Charset.find(ch)<Charset.npos) // (Befindet sich ch im Charset an x-beliebiger Position?)
	rc=true;
  return rc;
}
*/
