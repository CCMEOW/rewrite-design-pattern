#ifndef _DERECTORY_H_
#define _DERECTORY_H_

#include <list>
#include <vector>
#include "Entry.h"
using namespace std;


class Directory : public Entry
{
private:
	string name;
	list<Entry*> directory;
public:
	Directory(string name);
	string getName() const;
	float getSize();
	Entry* add(Entry *entry);
	Entry* deleteFile(string name);
	Entry* findEntry(string name);
	Entry* findEntryFromRoot(string name,Directory* rootDir);
	void printList();
	string toString();
	static Directory* createDirectory(string name);
	~Directory();
private:
	void spliteString(const string&s, vector<string>& v, const string& c);
	void printList(string prefix);
};


#endif
