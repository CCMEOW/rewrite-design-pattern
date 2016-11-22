#ifndef _MYOBSERVER_H_
#define _MYOBSERVER_H_

#include <string>
using namespace std;

class MyObserver
{
public:
	MyObserver();
	~MyObserver();
	void update(string message);
private:
	
};

MyObserver::MyObserver()
{
}

MyObserver::~MyObserver()
{
}


#endif
