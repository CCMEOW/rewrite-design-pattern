#include "Rectangle.h"
#include "Globle.h"
#include <iostream>
using namespace std;

Rectangle::Rectangle(float length, float width):length(length),width(width){
	this->id = graph_id++;
}

void Rectangle::display(){
	cout << "Rectangle"<<id<<"[" << length << "," << width << "]" << endl;
}

Rectangle* Rectangle::createRectangle(float length, float width){
	if (length < 0 || width < 0){
		cout << "Invalid input. " << endl;
		return NULL;
	}
	return new Rectangle(length, width);
}


int Rectangle::getId()const{
	return id;
}