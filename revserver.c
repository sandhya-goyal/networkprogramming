#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
int main(){
char sendline[100];
char recvline[100];
int clientlen=0;
struct sockaddr_in ser;
struct sockaddr_in cli;
int sockid;
sockid=socket(PF_INET,SOCK_STREAM,0);
ser.sin_family=AF_INET;
ser.sin_addr.s_addr = htonl(INADDR_ANY);	
ser.sin_port = htons(22002);
bind(sockid,(struct sockaddr *)&ser, sizeof(ser));
listen(sockid,5); //10 is maximum u can mention any it is the queue limit nonn blocking
int clientid=accept(sockid,(struct sockaddr *)&cli, &clientlen);
memset(recvline,'\0',sizeof(recvline));
recv(clientid,recvline,100,0);
int s= strlen(recvline)-2;
printf("%d",s);
int i=0;
int flag=1;
while(i<s){
    char temp=recvline[i];
    recvline[i]=recvline[s];
    recvline[s]=temp;
    s--;
    i++;
}
send(clientid,recvline,strlen(recvline),0);
close(sockid);
}