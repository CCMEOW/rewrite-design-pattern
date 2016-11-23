#ifndef _HEATER_H_
#define _HEATER_H_

#include "Observable.h"
#include "Listener.h"

class Heater : public Observable
{
public:
	Heater();
	~Heater();

	void change();
private:

};

#endif
