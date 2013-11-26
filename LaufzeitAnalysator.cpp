#include "LaufzeitAnalysator.h"

// Laufzeitformel vorbereiten
void LaufzeitAnalysator::laufzeit( grundlaufzeit, lastFaktor, last, tempFaktor, spannFaktor, proFaktor) {
    tempFaktor = Faktoren::getTemperatur();
    spannFaktor = Faktoren::getSpannung();
    proFaktor = Faktoren::getProzess();
    lastFaktor = Faktoren::getFaktoren();
    
    int zeit = ( grundlaufzeit + lastFaktor * last ) * tempFaktor * spannFaktor * proFaktor;
    
    
}