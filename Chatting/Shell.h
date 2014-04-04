#include <iostream>

// Text User Interface
#include "CustomShell.h"

#ifndef __SHELL_H__
#define __SHELL_H__

class Shell: public CustomShell
{
protected:
	virtual void createCommands(vector<CommandItem>& list);
public:
	Shell() : CustomShell("Client") {};
};

#endif