#ifndef _OBSERVABLE_H_
#define _OBSERVABLE_H_

#include <list>
#include "Observer.h"
using namespace std;

class Observable
{
public:
	Observable();
	~Observable();

	virtual void addObserver(Observer* observer);
	virtual bool deleteObserver(Observer* observer);
	virtual void notifyObservers();
	void setChanged();
	void clearChanged();

	virtual void change();
private:
	list<Observer*> observers;
	bool changed;
};


#endif
