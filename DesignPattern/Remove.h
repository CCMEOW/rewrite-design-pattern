#ifndef _REMOVE_H_
#define _REMOVE_H_

#include "Command.h"

class Graph;
class CommandManager;
class Remove : public Command{
public:
	void unexecute(CommandManager *cmdManager);
	bool execute(CommandManager *cmdManager);
	Remove(Graph *graph);
private:
	Graph* graph;
};

#endif
