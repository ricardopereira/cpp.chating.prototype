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
				cout << "Result: " << Test(TEXT("Teste da DLL")) << endl;
			}
			else if (sh.isCommand("x"))
			{
				cout << "Good bye" << endl;
				break;
			}
		}
	} while (!sh.toExit());

	return 0;
}