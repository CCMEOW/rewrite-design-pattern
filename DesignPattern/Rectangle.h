#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Graph.h"
class Rectangle : public Graph{
private:
	float length;
	float width;
public:
	void display();

	int getId()const;
	Rectangle(float length, float width);
	static Rectangle* createRectangle(float length, float width);
};
#endif
