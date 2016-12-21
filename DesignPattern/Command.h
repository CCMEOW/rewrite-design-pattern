#ifndef _COMMAND_H_
#define _COMMAND_H_

class CommandManager;
class Command{
public:
	virtual bool execute(CommandManager* cmdManager) = 0;
	virtual void unexecute(CommandManager* cmdManager) = 0;
};

#endif
