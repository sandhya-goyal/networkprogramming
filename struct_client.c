#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct desc{
    short int fd1,fd2;
}D;

struct result{
    short int max;
}M;

int main()
{
    char sendline[100];
    char recvline[100];
    int clientlen = 0;
    struct sockaddr_in cli;
    int clsockid;
    bzero(&cli, sizeof cli);
    clsockid = socket(AF_INET, SOCK_STREAM, 0);
    cli.sin_family = AF_INET;
    cli.sin_addr.s_addr = inet_addr("127.0.0.1");
    cli.sin_port = htons(22002);
    connect(clsockid, (struct sockaddr *)&cli, sizeof(cli));
    D.fd1=4;
    D.fd2=-1;
    send(clsockid,&D,sizeof(D),0);
    recv(clsockid,&M,sizeof(M),0);
    printf("max: %d\n",M.max);




    
    close(clsockid);
}