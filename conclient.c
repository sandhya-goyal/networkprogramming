#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
int main(){
int sockid;
int len;
char recvline[100],sendline[100],data[100];
sockid=socket(PF_INET,SOCK_STREAM,0);
struct sockaddr_in ser;
ser.sin_family=AF_INET;
ser.sin_port=htons(20200);
ser.sin_addr.s_addr=inet_addr("127.0.0.1");
connect(sockid,(struct sockaddr *)&ser,sizeof(ser));
printf(" Enter the first string\n");
memset(sendline,'\0',sizeof(sendline));
fgets(sendline,100,stdin);
sendline[strlen(sendline)-1]='\0';
send(sockid,sendline,strlen(sendline),0);
memset(sendline,'\0',sizeof(sendline));
printf(" Enter the second string\n");
fgets(sendline,100,stdin);
sendline[strlen(sendline)-1]='\0';
send(sockid,sendline,strlen(sendline),0);
memset(recvline,'\0',sizeof(recvline));
recv(sockid,recvline,100,0);
printf("%s",recvline);
close(sockid);

}