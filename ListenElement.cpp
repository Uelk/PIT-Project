#include "Listenelement.h"

// Attribute mit NULL initialisieren
ListenElement::ListenElement() {
	schaltwerkElement = NULL;
	next = NULL;
}

ListenElement::~ListenElement() {
}

// Rückgabe Schaltwerkelement
SchaltwerkElement* ListenElement::getSchaltwerkElement() {
	return schaltwerkElement;
}

// Rückgabe des nächsten Elements
ListenElement* ListenElement::getNextElement() {
	return next;
}

// Schalwerkelement festlegen
void ListenElement::setSchaltwerkElement( SchaltwerkElement* schaltwerkEl ) {
	schaltwerkElement = schaltwerkEl;
}

// nächstes Element festlegen
void ListenElement::setNextElement( ListenElement* nextEl ) {
	next = nextEl;
}