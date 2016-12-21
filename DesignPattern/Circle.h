#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Graph.h"
class Circle :public Graph{
public:
	void display();
	Circle(float radius);
	static Circle* createCircle(float radius);
	int getId()const;
private:
	float radius;
};
#endif
