#include "MyObserver.h"
#include <iostream>
using namespace std;

MyObserver::MyObserver(string name){
	this->name = name;
}

MyObserver::MyObserver()
{
}

MyObserver::~MyObserver()
{
}

void MyObserver::update(string message){
	cout << "receive update message: " + message << endl;
}