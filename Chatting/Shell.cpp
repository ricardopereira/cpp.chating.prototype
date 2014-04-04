#include "Shell.h"

void Shell::createCommands(vector<CommandItem>& list)
{
	list.push_back(CommandItem("login","username password")); //Ligas ao pipe
	list.push_back(CommandItem("x",""));
}