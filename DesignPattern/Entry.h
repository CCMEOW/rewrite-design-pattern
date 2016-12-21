#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <string>
using namespace std;

class Entry{

public:
	virtual string getName()const;
	virtual float getSize();
	virtual Entry* add(Entry* entry);
	virtual string toString()=0;
	virtual Entry* deleteFile(string name);
	virtual void printList(string prefix)=0;
	
};

#endif
