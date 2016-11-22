#include "MyObserver.h"
#include <iostream>
//using namespace std;

void MyObserver::update(string message){
	cout << "receive update message: " + message << endl;
}