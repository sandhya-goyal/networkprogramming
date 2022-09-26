#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
int main(){
int sockid,cliid;
int len;
char recvline[100],sendline[100],data[100];
sockid=socket(PF_INET,SOCK_STREAM,0);
struct sockaddr_in ser,cli;
ser.sin_family=AF_INET;
ser.sin_port=htons(20200);
ser.sin_addr.s_addr=htonl(INADDR_ANY);
if(bind(sockid,(struct sockaddr *)&ser,sizeof(ser))<0){
printf("Binding error ");
}
listen(sockid,10);
cliid=accept(sockid,(struct sockaddr *)&cli,&len);
memset(recvline,'\0',sizeof(recvline));
recv(cliid,recvline,100,0);
strcpy(data,recvline);
printf(" First String %s",recvline);
memset(recvline,'\0',sizeof(recvline));
recv(cliid,recvline,100,0);
printf(" Second String %s",recvline);
strcat(recvline,data);
memset(sendline,'\0',sizeof(sendline));
strncpy(sendline,recvline,100);
send(cliid,sendline,strlen(sendline),0);
close(sockid);








}