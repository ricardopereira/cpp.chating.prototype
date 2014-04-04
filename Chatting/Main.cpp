#include <iostream>
#include <windows.h>
#include <tchar.h>

#include "Shell.h"
#include "ChattingClient.h" //dll implicito

using namespace std;

#define BUFFERSIZE 512

int main()
{
	Shell sh;
	int connected = false;

	// Iniciar a shell
	sh.open();
	do
	{
		// Ler comando
		if (sh.readCommand())
		{
			// Verificar comando
			if (sh.isCommand("login"))
			{
				wcout << sh.getArgument(0) << endl;
				connected = Autenticar(sh.getArgument(0),sh.getArgument(1));
			}
			else if (sh.isCommand("x"))
			{
				if (connected)
				{
					Sair();
					connected = false;
				}
				cout << "Good bye" << endl;
				break;
			}
		}
	} while (!sh.toExit());

	return 0;
}