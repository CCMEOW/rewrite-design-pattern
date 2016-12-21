#include "Panel.h"
#include "Command.h"
#include "Graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

Panel::Panel(){

}

Panel::~Panel(){
	for each (Graph* graph in graphList)
	{
		delete graph;
	}
}

bool Panel::executeCommand(Command *cmd){
	if (!cmd->execute(this))
		return false;
	this->undos.push(cmd);
	return true;
}

void Panel::redo(){
	if (this->redos.size() < 1){
		return;
	}
	Command* cmd = this->redos.top();
	cmd->execute(this);
	this->undos.push(cmd);
	this->redos.pop();
}

void Panel::undo(){
	if (this->undos.size()<1)
	{
		return;
	}
	Command* cmd = this->undos.top();
	cmd->unexecute(this);
	this->redos.push(cmd);
	this->undos.pop();
}

void Panel::display(){
	cout << "This panel has: " << endl;
	for each (Graph* graph in graphList)
	{
		graph->display();
	}
}

list<Graph*>& Panel::getGraphList(){
	return graphList;
}

Graph* Panel::findGraph(int id){
	list<Graph*>::iterator it = find_if(graphList.begin(), graphList.end(), [id](const Graph* graph){return graph->getId() == id; });
	if (it != graphList.end()){
		return *it;
	}
	return NULL;
}