#include "MyObservable.h"

int main(){
	MyObservable* observable = new MyObservable();
	observable->addObserver(new MyObserver("observer1"));
	observable->addObserver(new MyObserver("observer2"));
	observable->setChanged();
	return 0;
}