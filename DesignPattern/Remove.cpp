#include "Remove.h"
#include "Panel.h"

bool Remove::execute(CommandManager *cmdManager){
	Panel* panel = (Panel*)cmdManager;
	if (this->graph == NULL){
		return false;
	}
	panel->getGraphList().remove(this->graph);
	return true;
}

void Remove::unexecute(CommandManager *cmdManager){
	Panel* panel = (Panel*)cmdManager;
	panel->getGraphList().push_back(this->graph);
}

Remove::Remove(Graph *graph){
	this->graph = graph;
}