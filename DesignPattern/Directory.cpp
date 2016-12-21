#include "Directory.h"
#include <iostream>
#include <algorithm>

Directory::Directory(string name){
	this->name = name;
}

string Directory::getName()const{
	return this->name;
}

float Directory::getSize(){
	float size = 0;
	for each (Entry* enrty in this->directory)
	{
		size += enrty->getSize();
	}
	return size;
}

Entry* Directory::add(Entry *entry){
	
	if (find_if(directory.begin(), directory.end(), [entry](const Entry *entryTmp){return entryTmp->getName() == entry->getName(); }) != directory.end()){
		//已有同名文件
		cout << "文件："+ entry->getName() + "已存在!" << endl;
		return this;
	}
	this->directory.push_back(entry);
	cout << entry->getName() << " created. " << endl;
	return this;
}

Entry* Directory::deleteFile(string name){
	list<Entry*>::iterator it = find_if(directory.begin(), directory.end(), [name](const Entry *entryTmp){return entryTmp->getName() == name; });
	if (it != directory.end()){
		delete *it;
		this->directory.remove(*it);
		cout << name << " deleted. " << endl;
	}
	else{
		cout << name << " not exist. " << endl;
	}
	//this->directory.remove_if([name](const Entry *entryTmp){return entryTmp->getName() == name; });
	return this;
}

void Directory::printList(){
	printList("");
}

void Directory::printList(string prefix){
	cout << prefix + "/" + this->toString()<<endl;
	for each (Entry* entry in this->directory)
	{
		entry->printList(prefix + "/" + this->name);
	}
}

string Directory::toString(){
	char* s = new char[];
	sprintf(s,"%.3f", getSize());
	return getName() + " (" + s + ") ";
}

Directory::~Directory(){
	for each (Entry* entry in this->directory)
	{
		entry->printList("");
		delete entry;

	}
}

Entry* Directory::findEntry(string name){
	if (name.find('.') != string::npos){
		return NULL;
	}
	list<Entry*>::iterator it = find_if(directory.begin(), directory.end(), [name](const Entry *entryTmp){return entryTmp->getName() == name; });
	if (it != directory.end()){
		return *it;
	}
	return NULL;
}

Directory* Directory::createDirectory(string name){
	if (name.find('.') != string::npos || name.find('/') != string::npos){
		cout << "Invalid name. " << endl;
		return NULL;
	}
	return new Directory(name);
}

void Directory::spliteString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

Entry* Directory::findEntryFromRoot(string name,Directory* rootDir){
	if (name.find('.') != string::npos){
		return NULL;
	}
	if (name.find('/') != string::npos){
		vector<string> pathVector;
		spliteString(name, pathVector, "/");
		//list<Entry*> currDirs = directory;
		Directory* currDir = rootDir;
		if (pathVector.size() < 2){
			return currDir;
		}
		if (pathVector[1] != "root"){
			return NULL;
		}
		for (int i = 2; i < pathVector.size(); ++i){
			string toFind = pathVector[i];
			list<Entry*>::iterator it = find_if(currDir->directory.begin(), currDir->directory.end(), [name,toFind](const Entry *entryTmp){return entryTmp->getName() == toFind; });
			Directory* tmpDir = currDir;
			if (it != tmpDir->directory.end()){
				currDir = (Directory*)*it;
			}
			else
			{
				return NULL;
			}
		}
		return currDir;
	}
	else{
		list<Entry*>::iterator it = find_if(directory.begin(), directory.end(), [name](const Entry *entryTmp){return entryTmp->getName() == name; });
		if (it != directory.end()){
			return *it;
		}
		else
		{
			return NULL;
		}
	}
	return NULL;
}
