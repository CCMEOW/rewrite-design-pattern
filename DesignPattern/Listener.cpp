#include "Listener.h"
#include <iostream>
using namespace std;

Listener::Listener()
{
}

Listener::~Listener()
{
}

Listener::Listener(string name){
	this->name = name;
}

void Listener::update(){
	cout << name + " is going to fetch water. " << endl;
}