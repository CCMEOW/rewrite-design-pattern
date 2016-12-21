#ifndef _FILE_H_
#define _FILE_H_

#include "Entry.h"

class File : public Entry{
private:
	string name;
	float size;
public:
	File(string name, float size);
	string getName()const;
	float getSize();
	string toString();
	static File* createFile(string name, float size);
protected:
	void printList(string prefix);

};

#endif
