#ifndef _ADD_H_
#define _ADD_H_

#include "Command.h"
class Graph;
class CommandManager;
class Add : public Command{
public:
	void unexecute(CommandManager *cmdManager);
	bool execute(CommandManager *cmdManager);
	Add(Graph* graph);
private:
	Graph* graph;
};

#endif
