// #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
// #include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	int clientSock,n;
	char sendline[100];
	char recvline[100];
	char first[100];
	struct sockaddr_in eachClntAddr;

	clientSock=socket(AF_INET,SOCK_STREAM,0);
	// PF_INET

	bzero(&eachClntAddr,sizeof eachClntAddr);
	
	eachClntAddr.sin_family=AF_INET;
	eachClntAddr.sin_port=htons(22002);
	eachClntAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //convert ip to network byte order
	
	//inet_pton(AF_INET,"127.0.0.1",&(eachClntAddr.sin_addr));
	// printf("%d\n",eachClntAddr.sin_port);
	connect(clientSock,(struct sockaddr *)&eachClntAddr,sizeof(eachClntAddr));
	// printf("%d\n",eachClntAddr.sin_port);
    
    memset(sendline,'\0',sizeof(sendline));

    fgets(sendline,sizeof(sendline),stdin);

    send(clientSock,sendline,strlen(sendline),0);

    memset(sendline,'\0',sizeof(sendline));
    
    fgets(sendline,sizeof(sendline),stdin);

    send(clientSock,sendline,strlen(sendline),0);

    memset(recvline,'\0',sizeof(recvline));
    recv(clientSock,recvline,sizeof(recvline),0);
    printf("Result: %s\n",recvline);

    
	// while(1)       
	// {
	//  	bzero( sendline, 100);
	// 	bzero( recvline, 100);

	// 	fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
	// 	send(clientSock,sendline,strlen(sendline),0);	//0 is a flag
	// 	recv(clientSock,recvline,100,0);
	// 	strcpy(first,recvline);
	// 	printf("%s",recvline);
	// }
	close(clientSock);
	
}
