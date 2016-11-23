#include "Heater.h"
#include "Listener.h"
#include <iostream>
using namespace std;

int main(){

	Heater* heater = new Heater();

	Listener* John = new Listener("John");
	heater->addObserver(John);
	heater->addObserver(new Listener("xiao hong"));
	heater->addObserver(John);
	heater->change();
	return 0;
}





