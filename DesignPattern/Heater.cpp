#include "Heater.h"
#include <iostream>
#include <windows.h>
using namespace std;

Heater::Heater():time(3){}

Heater::~Heater(){}


void Heater::change(){
	setChanged();
	cout << "Time Up!" << endl;
	Sleep(1000);
	notifyObservers();
	clearChanged();
}

void Heater::setTime(int time){
	this->time = time;
}

void Heater::start(){
	cout << "Start boiling water, wait..." << endl;
	for (int i = 0; i < time; ++i){
		Sleep(1000);
	}
	change();
}

