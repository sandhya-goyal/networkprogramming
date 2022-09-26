#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main()
{
    char sendline[100];
    char recvline[100];
    int clientlen = 0;
    struct sockaddr_in cli, client;
    int clsockid;
    int len;
    bzero(&cli, sizeof cli);
    clsockid = socket(AF_INET, SOCK_STREAM, 0);
    cli.sin_family = AF_INET;
    cli.sin_addr.s_addr = htonl(INADDR_ANY);
    cli.sin_port = htons(20034);
    if(bind(clsockid, (struct sockaddr *)&cli, sizeof(cli))<0){
        printf("bind error!\n");
    }
    listen(clsockid, 10);
    int clientSock = accept(clsockid, (struct sockaddr *)&client, &len);
    printf("sock: %d\n",clientSock);
    for (;;)
    {
        memset(recvline, '\0', sizeof(recvline));
        recv(clientSock, recvline, 100, 0);
        printf("From Client %s", recvline);
        memset(sendline, '\0', sizeof(sendline));
        printf("Enter your message: ");
        fgets(sendline, sizeof(sendline), stdin);
        send(clientSock, sendline, strlen(sendline), 0);
    }
close(clsockid);
}