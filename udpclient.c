#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>

void echo( int sockfd, const struct sockaddr *pservaddr, socklen_t servlen)
{
	int n;
	char sendline[1023], recvline[1024];
	while (fgets(sendline, 1023, stdin) != NULL) 
	{
		sendto(sockfd, sendline, strlen(sendline), 0, pservaddr, servlen);
		n = recvfrom(sockfd, recvline, 1023, 0, NULL, NULL);
		recvline[n] = '\0'; /* null terminate */
		fputs(recvline, stdout);
	}
}
int main(){
    struct sockaddr_in saddr;
    bzero(&saddr,sizeof(saddr));
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(10289);
    inet_pton(AF_INET,"127.0.0.1",&saddr.sin_addr);
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
    echo(sockfd,(struct sockaddr *)&saddr,sizeof(saddr));
}
