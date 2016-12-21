#include "File.h"

#include <iostream>

File::File(string name, float size){
	this->name = name;
	this->size = size;
}

string File::getName()const{
	return this->name;
}

float File::getSize(){
	return this->size;
}

string File::toString(){
	char* s = new char[];
	sprintf(s, "%.3f", getSize());
	return getName() + " (" + s + ") ";
}



void File::printList(string prefix){
	cout << prefix + "/" + this->toString() << endl;
}

File* File::createFile(string name, float size){
	if (name.find('.') == string::npos){
		cout << "Invalid name. " << endl;
		return NULL;
	}
	return new File(name, size);
}