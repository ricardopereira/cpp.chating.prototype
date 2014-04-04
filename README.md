# Chatting v0 - Prototype
#### Visual Studio 2012 C++ project

###### ChattingServer

Server command line
```
server>start
_ (waiting for client connection)
```

###### ChattingClient

DLL for client use

Note: only *Autenticar* is implemented for testing.
```cpp
int Autenticar(TCHAR *login, TCHAR *pass);
int LerListaUtilizadores(UTILIZADOR *utilizadores);
int IniciarConversa(TCHAR *utilizador);
int DesligarConversa();
int EnviarMensagemPrivada(TCHAR *msg);
int EnviarMensagemPublica(TCHAR *msg);
CHAT LerInformacaoInicial();
void LerMensagensPublicas();
void LerMensagensPrivadas();
int Sair();
int Desligar();
```

###### Chatting

Client example: use DLL

Testing with server running:
```
client>login admin admin
_ (sending request)
```

```
server>start
Login approved for Admin
Client disconnected
```

###### Core

Core classes

###### Logic

Logic classes

###### TUI

Text User Interface classes
