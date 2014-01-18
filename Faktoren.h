#ifndef FAKTOREN_H
#define FAKTOREN_H

#include <iostream>
#include "itiv_win_drv.h"
using namespace std;

class Faktoren {
private:
	double spannung;
	double temperatur;
	double prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;
	bool berechneSpannungFaktor( double );
	bool berechneTemperaturFaktor( double );
	bool berechneProzessFaktor( short );
	double berechneFaktor( double, double [][2], int );
	double interpolation( double, double, double, double, double );
	ItivDev_Config* DevPtr;
	bool debug;
	void readFactorFromDevice();
	bool startDeviceMeasurement();
public:
	Faktoren();
	~Faktoren();
	double getSpannung();
	double getTemperatur();
	short getProzess();
	double getTemperaturFaktor();
	double getSpannungFaktor();
	double getProzessFaktor();
	bool setSpannung( double );
	bool setTemperatur( double );
	bool setProzess( short );
	void ausgabeFaktoren();
};
#endif