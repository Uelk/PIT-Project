#include "Listenelement.h"

ListenElement::ListenElement() {
	schaltwerkElement = NULL;
	next = NULL;
}

ListenElement::~ListenElement() {
}

SchaltwerkElement* ListenElement::getSchaltwerkElement() {
	return schaltwerkElement;
}

ListenElement* ListenElement::getNextElement() {
	return next;
}

void ListenElement::setSchaltwerkElement( SchaltwerkElement* schaltwerkEl ) {
	schaltwerkElement = schaltwerkEl;
}

void ListenElement::setNextElement( ListenElement* nextEl ) {
	next = nextEl;
}