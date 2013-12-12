#include "Listenelement.h"

// Attribute mit NULL initialisieren
ListenElement::ListenElement() {
	schaltwerkElement = NULL;
	next = NULL;
}

ListenElement::~ListenElement() {
}

// Rueckgabe Schaltwerkelement
SchaltwerkElement* ListenElement::getSchaltwerkElement() {
	return schaltwerkElement;
}

// Rueckgabe des naechsten Elements
ListenElement* ListenElement::getNextElement() {
	return next;
}

// Schalwerkelement festlegen
void ListenElement::setSchaltwerkElement( SchaltwerkElement* schaltwerkEl ) {
	schaltwerkElement = schaltwerkEl;
}

// naechstes Element festlegen
void ListenElement::setNextElement( ListenElement* nextEl ) {
	next = nextEl;
}