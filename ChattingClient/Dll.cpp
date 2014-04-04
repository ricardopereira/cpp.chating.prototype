﻿#include <windows.h>
#include <tchar.h>

#include "Dll.h"
#include "ChatComunication.h"

int Test(PTCHAR str)
{
	if (!str) return -1;
	// Devolve o numero de caracteres
	return _tcslen(str);
}

int Autenticar(TCHAR *login, TCHAR *pass)
{
	HANDLE hPipe;
	PTCHAR pMsg = TEXT("Teste de mensagem");

    hPipe = CreateFile( 
        pipeName,
        GENERIC_READ | GENERIC_WRITE,
        0, //no sharing
        NULL, //default security attributes
        OPEN_EXISTING, //opens existing pipe
        0, //default attributes
        NULL); //no template file

    if (hPipe == INVALID_HANDLE_VALUE)
        return 0;

    if (GetLastError() == ERROR_PIPE_BUSY) 
        return 0;

	PTCHAR msg = TEXT("Ligacao com sucesso");
	DWORD msgBytes;
	DWORD msgBytesSent;
	BOOL success = 0;

	// Enviar mensagem
	msgBytes = (_tcslen(msg)+1)*sizeof(TCHAR);

	success = WriteFile(hPipe, 
		msg, //message 
		msgBytes, //message length 
		&msgBytesSent, //bytes written 
		NULL); //not overlapped 

	if (!success) 
		return -1;

	// Testar a desconectar o cliente
	Sleep(30000);

	// Fecha o pipe
	CloseHandle(hPipe);

	return 1;
}

int LerListaUtilizadores(UTILIZADOR *utilizadores)
{
	return 0;
}

int IniciarConversa(TCHAR *utilizador)
{
	return 0;
}

int DesligarConversa()
{
	return 0;
}

int EnviarMensagemPrivada(TCHAR *msg)
{
	return 0;
}

void EnviarMensagemPublica(TCHAR *msg)
{
	
}

CHAT LerInformacaoInicial()
{
	CHAT dumb;
	return dumb;
}

void LerMensagensPublicas()
{

}

void LerMensagensPrivadas()
{

}

int Sair()
{
	return 0;
}

int Desligar()
{
	return 0;
}