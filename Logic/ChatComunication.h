/*Valores maximos*/
#define MAXLOGIN 20
#define MAXCOMMAND 50
#define MAXCOMMANDARGS 5
#define MAXPIPE 15
#define MAXMESSAGE 255

/*Comunicacao*/
typedef struct recRequest Request, *pRequest;

struct recRequest {
    int pid;
    char username[MAXLOGIN];
    char password[MAXLOGIN];
    char command[MAXCOMMAND];
};