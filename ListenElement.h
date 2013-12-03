#ifndef LISTENELEMENT_H
#define LISTENELEMENT_H

#include "SchaltwerkElement.h"
using namespace std;

class ListenElement {
private:
	SchaltwerkElement* schaltwerkElement;
	ListenElement* next;
public:
	ListenElement();
	~ListenElement();
	SchaltwerkElement* getSchaltwerkElement();
	ListenElement* getNextElement();
	void setSchaltwerkElement( SchaltwerkElement* );
	void setNextElement( ListenElement* );
};
#endif 