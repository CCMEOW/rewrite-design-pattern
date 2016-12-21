#ifndef _PANEL_H_
#define _PANEL_H_

#include <list>
#include "CommandManager.h"

class Graph;
class Panel :public CommandManager{
public:
	void display();
	std::list<Graph*>& getGraphList();
	bool executeCommand(Command *cmd);
	Graph* findGraph(int id);
	void undo();
	void redo();
	Panel();
	~Panel();
private:
	std::list<Graph*> graphList;
};

#endif
