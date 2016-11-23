#include "MyObservable.h"
#include <iostream>
using namespace std;

MyObservable::MyObservable()
{
	changed = false;
}

MyObservable::~MyObservable()
{
	for (auto iter = myObservers.begin(); iter != myObservers.end();)
	{
		myObservers.erase(iter++);
	}
}

void MyObservable::addObserver(MyObserver* observer){
	myObservers.push_back(observer);
}

bool MyObservable::deleteObserver(MyObserver* observer){
	//auto iter = myObservers.begin();
	auto iter = find(myObservers.begin(), myObservers.end(), observer);
	if (iter!=myObservers.end())
	{
		myObservers.erase(iter);
		return true;
	}
	return false;
}

void MyObservable::notifyObservers(){
	if (changed){
		for (auto iter = myObservers.begin(); iter != myObservers.end(); ++iter)
		{
			(*iter)->update("updated!");
		}
		clearChanged();
	}

}


void MyObservable::setChanged(){
	changed = true;
	cout << "observable has changed!" << endl;
	notifyObservers();
}

void MyObservable::clearChanged(){
	changed = false;
}