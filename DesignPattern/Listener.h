#ifndef _LISTENER_H_
#define _LISTENER_H_

#include "Observer.h"

class Listener : public Observer
{
public:
	Listener();
	Listener(string name);
	~Listener();

	void update();
private:
	string name;
};



#endif
