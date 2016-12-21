#include "Circle.h"
#include "Globle.h"
#include <stdlib.h>
#include <iostream>

using namespace std;


Circle::Circle(float radius):radius(radius){
	this->id = graph_id++;
}

void Circle::display(){
	cout << "Circle"<< id<<"[" << radius << "]" << endl;
}

Circle* Circle::createCircle(float radius){
	if (radius < 0){
		cout << "Invalid radius" << endl;
		return NULL;
	}
	return new Circle(radius);
}


int Circle::getId()const{
	return id;
}