#ifndef _MYOBSERVER_H_
#define _MYOBSERVER_H_

#include <list>
using namespace std;

class MyObserver;

class MyObservable
{
public:
	MyObservable();
	~MyObservable();

	bool addObserver(MyObserver observer);
	bool deleteObserver(MyObserver observer);
	bool notifyObservers();

private:
	list<MyObserver> myObservers;
	bool changed;
};

MyObservable::MyObservable()
{
}

MyObservable::~MyObservable()
{
}

#endif
