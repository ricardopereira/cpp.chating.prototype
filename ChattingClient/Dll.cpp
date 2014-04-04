#include <windows.h>
#include <tchar.h>

#include "Dll.h"

int Test(PTCHAR str)
{
	if (!str) return -1;
	// Devolve o numero de caracteres
	return _tcslen(str);
}

int Autenticar(TCHAR *login, TCHAR *pass)
{
	return 0;
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