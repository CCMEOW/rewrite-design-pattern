#ifndef _MYOBSERVABLE_H_
#define _MYOBSERVABLE_H_

#include <list>
#include "MyObserver.h"
using namespace std;

class MyObservable
{
public:
	MyObservable();
	~MyObservable();

	void addObserver(MyObserver* observer);
	bool deleteObserver(MyObserver* observer);
	void notifyObservers();
	void setChanged();
	void clearChanged();
private:
	list<MyObserver*> myObservers;
	bool changed;
};


#endif
