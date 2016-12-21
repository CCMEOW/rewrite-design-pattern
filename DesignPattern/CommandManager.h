#ifndef _COMMANDMANAGER_H_
#define _COMMANDMANAGER_H_

#include <stack>

class Command;
class CommandManager{
public:
	virtual bool executeCommand(Command *cmd) = 0;
	virtual void redo() = 0;
	virtual void undo() = 0;
protected:
	std::stack<Command*> undos;
	std::stack<Command*> redos;

};

#endif
