#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <string>
using namespace std;

class Observer
{
public:
	Observer();
	Observer(string name);
	~Observer();
	virtual void update();
private:
	string name;
};


#endif
