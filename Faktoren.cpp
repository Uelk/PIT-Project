#include "Faktoren.h"
using namespace std;

// Berechnung Spannungsfaktor
bool Faktoren::berechneSpannungFaktor( double spg ) {
	const int laenge = 7;
	double spgFaktorTabelle[laenge][2];
	spgFaktorTabelle[0][0] = 1.08;
	spgFaktorTabelle[0][1] = 1.121557;
	spgFaktorTabelle[1][0] = 1.12;
	spgFaktorTabelle[1][1] = 1.075332;
	spgFaktorTabelle[2][0] = 1.16;
	spgFaktorTabelle[2][1] = 1.035161;
	spgFaktorTabelle[3][0] = 1.20;
	spgFaktorTabelle[3][1] = 1.0;
	spgFaktorTabelle[4][0] = 1.24;
	spgFaktorTabelle[4][1] = 0.968480;
	spgFaktorTabelle[5][0] = 1.28;
	spgFaktorTabelle[5][1] = 0.940065;
	spgFaktorTabelle[6][0] = 1.32;
	spgFaktorTabelle[6][1] = 0.914482;
	Faktoren::spannungFaktor = berechneFaktor( spg, spgFaktorTabelle, laenge );
	return true;
}

// Berechnung Temperaturfaktor
bool Faktoren::berechneTemperaturFaktor( double temp ) {
	const int laenge = 15;
	double tempFaktorTabelle[laenge][2];
	tempFaktorTabelle[0][0] = -25.0;
	tempFaktorTabelle[0][1] = 0.897498;
	tempFaktorTabelle[1][0] = -15;
	tempFaktorTabelle[1][1] = 0.917532;
	tempFaktorTabelle[2][0] = 0.0;
	tempFaktorTabelle[2][1] = 0.948338;
	tempFaktorTabelle[3][0] = 15.0;
	tempFaktorTabelle[3][1] = 0.979213;
	tempFaktorTabelle[4][0] = 25.0;
	tempFaktorTabelle[4][1] = 1.0;
	tempFaktorTabelle[5][0] = 35.0;
	tempFaktorTabelle[5][1] = 1.020305;
	tempFaktorTabelle[6][0] = 45.0;
	tempFaktorTabelle[6][1] = 1.040540;
	tempFaktorTabelle[7][0] = 55.0;
	tempFaktorTabelle[7][1] = 1.061831;
	tempFaktorTabelle[8][0] = 65.0;
	tempFaktorTabelle[8][1] = 1.082983;
	tempFaktorTabelle[9][0] = 75.0;
	tempFaktorTabelle[9][1] = 1.103817;
	tempFaktorTabelle[10][0] = 85.0;
	tempFaktorTabelle[10][1] = 1.124124;
	tempFaktorTabelle[11][0] = 95.0;
	tempFaktorTabelle[11][1] = 1.144245;
	tempFaktorTabelle[12][0] = 105.0;
	tempFaktorTabelle[12][1] = 1.164563;
	tempFaktorTabelle[13][0] = 115.0;
	tempFaktorTabelle[13][1] = 1.184370;
	tempFaktorTabelle[14][0] = 125.0;
	tempFaktorTabelle[14][1] = 1.204966;
	Faktoren::temperaturFaktor = berechneFaktor( temp, tempFaktorTabelle, laenge );
	return true;
}

// Berechnung Prozessfaktor
bool Faktoren::berechneProzessFaktor( short prz ) {
	const int laenge = 3;
	double prozessFaktorTabelle[laenge][2];
	prozessFaktorTabelle[0][0] = 1.0;
	prozessFaktorTabelle[0][1] = 1.174235;
	prozessFaktorTabelle[1][0] = 2.0;
	prozessFaktorTabelle[1][1] = 1.0;
	prozessFaktorTabelle[2][0] = 3.0;
	prozessFaktorTabelle[2][1] = 0.876148;
	if( prz == 1.0 || prz == 2.0 || prz == 3.0 ) {
		Faktoren::prozessFaktor = berechneFaktor( prz, prozessFaktorTabelle, laenge );
		return true;
	}
	return false;
}

// uebergebenes Array nach Wert untersuchen
double Faktoren::berechneFaktor( double value, double arr[][2], int laenge ) {
    // Wert im Array vorhanden
	for( int i = 0; i < laenge; i++ ) {
		if( arr[i][0] == value ) {
			return arr[i][1];
		}
	}
	int x1_pos = 0;
	double x1;
	double y1;
	double x2;
	double y2;
    // Wert im Array nicht vorhanden
	for( int i = 0; i < laenge; i++ ) {
		if( arr[i][0] <= value ) {
			x1_pos = i; 
		}
	}
	x1 = arr[x1_pos][0];
	y1 = arr[x1_pos][1];
	x2 = arr[x1_pos + 1][0];
	y2 = arr[x1_pos + 1][1];
	return interpolation( value, x1, x2, y1, y2 );
}

// Interpolation zwischen 2 Werten
double Faktoren::interpolation( double value, double x1, double x2, double y1, double y2 ) {
	double steigung = ( y2 - y1 ) / ( x2 - x1 );
	double deltaX = value - x1;
	return y1 + ( steigung * deltaX );
}

Faktoren::Faktoren() {
	spannung = 0.0;
	temperatur = 0.0;
	prozess = 0.0;
	spannungFaktor = 0.0;
	temperaturFaktor = 0.0;
	prozessFaktor = 0.0;
	DevPtr = ItivDev_GetConfigByName( "Global\\ITIV_WindowsDevice" );
}

Faktoren::~Faktoren() {
	ItivDev_ReleaseDevice( DevPtr );
}

// Spannungswert holen
double Faktoren::getSpannung() {
	return spannung;
}

// Temperaturwert holen
double Faktoren::getTemperatur() {
	return temperatur;
}

// Prozesstyp holen
short Faktoren::getProzess() {
	return ( short ) prozess;
}

// Faktorenwerte holen
double Faktoren::getTemperaturFaktor() {
	return temperaturFaktor;
}

double Faktoren::getSpannungFaktor() {
	return spannungFaktor;
}

double Faktoren:: getProzessFaktor() {
	return prozessFaktor;
}

// Spannung festlegen
bool Faktoren::setSpannung( double spannung ) {
	Faktoren::spannung = spannung;
	berechneSpannungFaktor( spannung );
	return true;
}

// Temperatur festlegen
bool Faktoren::setTemperatur( double temperatur ) {
	Faktoren::temperatur = temperatur;
	berechneTemperaturFaktor( temperatur );
	return true;
}

// Prozess festlegen
bool Faktoren::setProzess( short prozess ) {
	Faktoren::prozess = prozess;
	berechneProzessFaktor( prozess );
	return true;
}

// Ausgabe berechneter Faktoren
void Faktoren::ausgabeFaktoren() {
	cout << "Faktoren: KV: ";
	cout << Faktoren::spannungFaktor;
	cout << " |KT: ";
	cout << Faktoren::temperaturFaktor;
	cout << " |KP: ";
	cout << Faktoren::prozessFaktor;
	cout << endl;
}