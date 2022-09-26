#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
void echo(int sockfd,struct sockaddr *pcliaddr, socklen_t clilen){
    int n;
	socklen_t len;
	char mesg[1024];
	for ( ; ; ) {
		len = clilen;
		n = recvfrom(sockfd, mesg, 1024, 0, pcliaddr, &len);
		printf("Echoing back - %s",mesg);	
		sendto(sockfd, mesg, n, 0, pcliaddr, len);
}}
int main(){
    struct sockaddr_in saddr ,claddr;
    bzero(&saddr,sizeof(saddr));
    bzero(&claddr,sizeof(claddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(10289);
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    bind(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
    echo(sockfd,(struct sockaddr *)&claddr,sizeof(claddr));
    close(sockfd);
}
