#ifndef _MYOBSERVER_H_
#define _MYOBSERVER_H_

#include <string>
using namespace std;

class MyObserver
{
public:
	MyObserver();
	MyObserver(string name);
	~MyObserver();
	void update(string message);
private:
	string name;
};



#endif
