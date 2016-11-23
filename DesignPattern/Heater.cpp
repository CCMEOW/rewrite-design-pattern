#include "Heater.h"
#include <iostream>
using namespace std;

Heater::Heater(){}

Heater::~Heater(){}


void Heater::change(){
	setChanged();
	cout << "Time Up!" << endl;
	notifyObservers();
	clearChanged();
}

