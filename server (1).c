/*Required Headers*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>


//recv and send return the number of bytes successfully read and write and -1 for error
//close 0 success -1 failure

//concept of indi


int main()
{
	char str[100];
	int servSock, clientSock;
	struct sockaddr_in echoServAddr;
	struct sockaddr_in client;
	int clientlen=0;
	char clientip[100];
    // char sendline[100];
    char first[100];
    char recvline[100];

	servSock = socket(PF_INET, SOCK_STREAM, 0);

	bzero(&echoServAddr, sizeof(echoServAddr));  //clear buffer 

	echoServAddr.sin_family = AF_INET;
	echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);	//htonl = host to network byte order l is for long
	echoServAddr.sin_port = htons(22002);	//host byte addr to network byte order (both 16 bits as 2^16 ports)

	bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)); //-1 if failure (port already in use)

	listen(servSock, 10);	//10 = max listeners

    clientSock = accept(servSock, (struct sockaddr *)&client, &clientlen);

    recv(clientSock,recvline,100,0);
    strcpy(first,recvline);
    recv(clientSock,recvline,100,0);

    if(strcmp(first,recvline)==0){
        strcpy(recvline,"equal!");
        send(clientSock,recvline,strlen(recvline),0);
    }else{
        strcpy(recvline,"not equal!");
        send(clientSock,recvline,strlen(recvline),0);
    }

	// while (1)
	// {
	// 	clientSock = accept(servSock, (struct sockaddr *)&client, &clientlen);		//client socket addr
	// 	bzero(str, 100);						//clientSock is a socket on serverside made for the communication for given client
	// 	recv(clientSock, str, 100, 0);	//0 is a flag
	// 	// client.sin_port = ntohs(client.sin_port);
	// 	printf("Connected to ip: %s,port : %d\n",inet_ntop(AF_INET,&client.sin_addr,clientip,100),ntohs(client.sin_port));
	// 	printf("Echoing back - %s", str);
	// 	send(clientSock, str, strlen(str), 0);
	// 	printf("%d\n",clientSock);
	// 	close(clientSock);
	// }
	close(servSock);
	return 0;
}



// // #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>
// // #include <netdb.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main(int argc,char **argv)
// {
// 	int clientSock,n;
// 	char sendline[100];
// 	char recvline[100];
// 	char first[100];
// 	struct sockaddr_in eachClntAddr;

// 	clientSock=socket(AF_INET,SOCK_STREAM,0);
// 	// PF_INET

// 	bzero(&eachClntAddr,sizeof eachClntAddr);
	
// 	eachClntAddr.sin_family=AF_INET;
// 	eachClntAddr.sin_port=htons(22002);
// 	eachClntAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //convert ip to network byte order
	
// 	//inet_pton(AF_INET,"127.0.0.1",&(eachClntAddr.sin_addr));
// 	// printf("%d\n",eachClntAddr.sin_port);
// 	connect(clientSock,(struct sockaddr *)&eachClntAddr,sizeof(eachClntAddr));
// 	// printf("%d\n",eachClntAddr.sin_port);

//     recv(clientSock,recvline,100,0);
//     strcpy(first,recvline);
//     recv(clientSock,recvline,100,0);

//     if(strcmp(first,recvline)==0){
//         strcpy(sendline,"equal!");
//         send(clientSock,sendline,strlen(sendline),0);
//     }else{
//         strcpy(sendline,"not equal!");
//         send(clientSock,sendline,strlen(sendline),0);
//     }
// 	// while(1)       
// 	// {
// 	//  	bzero( sendline, 100);
// 	// 	bzero( recvline, 100);

// 	// 	fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
// 	// 	send(clientSock,sendline,strlen(sendline),0);	//0 is a flag
		
// 	// 	strcpy(first,recvline);
// 	// 	printf("%s",recvline);
// 	// }
// 	close(clientSock);
	
// }
