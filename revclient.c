#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
char sendline[100];
char recvline[100];
int clientlen=0;
struct sockaddr_in cli;
int clsockid;
bzero(&cli,sizeof cli);
clsockid=socket(AF_INET,SOCK_STREAM,0);
cli.sin_family= AF_INET;
cli.sin_addr.s_addr = inet_addr("127.0.0.1");	
cli.sin_port = htons(22002);
connect(clsockid,(struct sockaddr *)&cli,sizeof(cli));
memset(sendline,'\0',sizeof(sendline));
fgets(sendline,sizeof(sendline),stdin);
send(clsockid,sendline,strlen(sendline),0);
memset(recvline,'\0',sizeof(recvline));
recv(clsockid,recvline,100,0);
printf("%s",recvline);
close(clsockid);
}