#include <windows.h>

#include "ChatClasses.h"

#ifdef CHATTINGCLIENT_EXPORTS
	#define DLL_IMP_API __declspec(dllexport)
#else
	#define DLL_IMP_API __declspec(dllimport)
#endif

extern "C"
{
	//Funções a serem exportadas/importadas
	DLL_IMP_API int Test(PTCHAR str);
	DLL_IMP_API int Autenticar(const TCHAR *login, const TCHAR *pass);
	DLL_IMP_API int LerListaUtilizadores(UTILIZADOR *utilizadores); //{?}
	DLL_IMP_API int IniciarConversa(TCHAR *utilizador);
	DLL_IMP_API int DesligarConversa();
	DLL_IMP_API int EnviarMensagemPrivada(const TCHAR *msg);
	DLL_IMP_API void EnviarMensagemPublica(const TCHAR *msg);
	DLL_IMP_API CHAT LerInformacaoInicial(); //{?}
	DLL_IMP_API void LerMensagensPublicas();
	DLL_IMP_API void LerMensagensPrivadas();
	DLL_IMP_API int Sair();
	DLL_IMP_API int Desligar();
}