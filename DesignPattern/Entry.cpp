#include "Entry.h"
#include <exception>
#include <iostream>

Entry* Entry::add(Entry* entry){
	throw runtime_error("错误调用基类的add方法");
}

Entry* Entry::deleteFile(string name){
	throw runtime_error("错误调用基类的deleteFile方法");
}

string Entry::getName()const{
	throw runtime_error("错误调用基类的getName方法");
}

float Entry::getSize(){
	throw runtime_error("错误调用基类的getSize方法");
}


//void Entry::printList(){
//	printList("");
//}

//void Entry::printList(string prefix){
//	throw runtime_error("错误调用基类的printList方法");
//}

//string Entry::toString(){
//	return getName() + "(" + to_string(getSize()) + ")";
//}