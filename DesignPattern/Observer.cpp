#include "Observer.h"
#include <iostream>
using namespace std;

Observer::Observer(string name){
	this->name = name;
}

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::update(){
	cout << name + " receive update message!" << endl;
}