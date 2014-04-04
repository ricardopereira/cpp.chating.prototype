#include <iostream>
#include <windows.h>
#include <tchar.h>

#include "Shell.h"

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
			if (sh.isCommand("start"))
			{
				// Teste
				HANDLE hPipe;
				BOOL connected = 1;
				PTCHAR pipeName = TEXT("\\\\.\\pipe\\pipeserver"); //LPTSTR

				hPipe = CreateNamedPipe(pipeName,
					PIPE_ACCESS_DUPLEX, //OpenMode
					PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, //PipeMode
					PIPE_UNLIMITED_INSTANCES, //MaxInstances
					BUFFERSIZE, //Int
					BUFFERSIZE, //Out
					0, //Timeout
					NULL); //Security

				// Verificar se pipe foi instanciado
				if (hPipe == INVALID_HANDLE_VALUE)
				{
					cout << TEXT("CreateNamedPipe failed: ") << GetLastError() << endl;
					return -1;
				}

				// Esperar pelo cliente
				connected = ConnectNamedPipe(hPipe,NULL);
				// Verificar conectividade
				if (connected && GetLastError() != ERROR_PIPE_CONNECTED)
				{
					// Cliente conectado
					cout << TEXT("Conexão com sucesso.") << endl;
				}

				// Fechar instancia do pipe
				CloseHandle(hPipe);
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