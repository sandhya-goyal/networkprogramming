#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
int main(){
    struct sockaddr_in saddr ,claddr;
    char mesg[1024];
    char sendline[1023], recvline[1024];
    socklen_t len;
    len=sizeof(claddr);
    bzero(&saddr,sizeof(saddr));
    bzero(&claddr,sizeof(claddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(20200);
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
	 recvfrom(sockfd, recvline, 1024, 0, (struct sockaddr *)&claddr,&len);
    printf("RECV STRING %s \n",recvline);
    int flag=1;
    int i=0;
    int s=strlen(recvline)-2;
    while(i<=s){
    if(recvline[i]!=recvline[s]){
        flag=0;
        break;
    }
    s--;
    i++;
}
if(flag==0){
    memset(recvline,'\0',sizeof(recvline));
    strcpy(recvline,"Not palindrome");
    sendto(sockfd, recvline, strlen(recvline), 0, (struct sockaddr *)&claddr,len);}
else{
    memset(recvline,'\0',sizeof(recvline));
    strcpy(recvline,"palindrome");
    sendto(sockfd, recvline, strlen(recvline), 0, (struct sockaddr *)&claddr,len);
}	
close(sockfd);
}