#include "Entry.h"
#include <exception>
#include <iostream>

Entry* Entry::add(Entry* entry){
	throw runtime_error("������û����add����");
}

Entry* Entry::deleteFile(string name){
	throw runtime_error("������û����deleteFile����");
}

string Entry::getName()const{
	throw runtime_error("������û����getName����");
}

float Entry::getSize(){
	throw runtime_error("������û����getSize����");
}


//void Entry::printList(){
//	printList("");
//}

//void Entry::printList(string prefix){
//	throw runtime_error("������û����printList����");
//}

//string Entry::toString(){
//	return getName() + "(" + to_string(getSize()) + ")";
//}