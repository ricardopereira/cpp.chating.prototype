#include <iostream>
#include <windows.h>
#include <tchar.h>

#include "Shell.h"
#include "ChatComunication.h"

using namespace std;

void comandStart();

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
				comandStart();
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

void comandStart()
{
	// Teste
	//while (1) {
		// Tratamento dos clientes

	//}

	// Um pipe
	HANDLE hPipe;
	BOOL connected = 1;
	BOOL success = 0;
				
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
		wcout << TEXT("CreateNamedPipe failed: ") << GetLastError() << endl;
		return;
	}

	// Esperar pelo cliente
	connected = ConnectNamedPipe(hPipe,NULL);
	// Verificar conectividade
	if (connected && GetLastError() != ERROR_PIPE_CONNECTED)
	{
		// Cliente conectado
		wcout << TEXT("Client connected") << endl;
	}

	// Ler mensagens
	TCHAR msg[BUFFERSIZE];
	DWORD msgBytes;

	while (1)
	{
		success = ReadFile(hPipe,
			msg, // buffer to receive data 
			BUFFERSIZE*sizeof(TCHAR), // size of buffer 
			&msgBytes, // number of bytes read 
			NULL); // not overlapped I/O 

		if (!success || msgBytes == 0)
		{   
			if (GetLastError() == ERROR_BROKEN_PIPE)
			{
				wcout << TEXT("Client disconnected: ") << GetLastError() << endl;
			}
			else
			{
				wcout << TEXT("ReadFile failed: ") << GetLastError() << endl;
			}
			break;
		}
		else
				wcout << msg << endl;
	}

	if (connected)
	{
		// Forca o envio das ultimas alteracoes
		FlushFileBuffers(hPipe); 
		// Desconectar
		DisconnectNamedPipe(hPipe);
	}

	// Fechar instancia do pipe
	CloseHandle(hPipe);
}