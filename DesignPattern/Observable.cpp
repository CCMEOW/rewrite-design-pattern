#include "Observable.h"
#include <iostream>
using namespace std;

Observable::Observable()
{
	changed = false;
}

Observable::~Observable()
{
	for (auto iter = observers.begin(); iter != observers.end();)
	{
		observers.erase(iter++);
	}
}

void Observable::addObserver(Observer* observer){
	auto iter = find(observers.begin(), observers.end(), observer);
	if (iter == observers.end()){
		observers.push_back(observer);
	}

}

bool Observable::deleteObserver(Observer* observer){
	auto iter = find(observers.begin(), observers.end(), observer);
	if (iter!=observers.end())
	{
		observers.erase(iter);
		return true;
	}
	return false;
}

void Observable::notifyObservers(){
	if (changed){
		for (auto iter = observers.begin(); iter != observers.end(); ++iter)
		{
			(*iter)->update();
		}
	}

}

void Observable::setChanged(){
	changed = true;
}

void Observable::clearChanged(){
	changed = false;
}

void Observable::change(){
	setChanged();
	cout << "I have changed!" << endl;
	notifyObservers();
	clearChanged();
}