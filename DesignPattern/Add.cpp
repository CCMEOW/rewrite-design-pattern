#include "Add.h"
#include "Panel.h"

void Add::unexecute(CommandManager *cmdManager){
	Panel* panel = (Panel*)cmdManager;
	panel->getGraphList().pop_back();
}

bool Add::execute(CommandManager *cmdManager){
	Panel* panel = (Panel*)cmdManager;
	if (this->graph == NULL)
		return false;
	panel->getGraphList().push_back(this->graph);
	return true;
}

Add::Add(Graph* graph){
	this->graph = graph;
}