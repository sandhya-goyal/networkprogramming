#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

struct desc{
    short int fd1,fd2;
}D;

struct result{
    short int max;
}M;


int main()
{
    int clientlen = 0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    int sockid;
    sockid = socket(PF_INET, SOCK_STREAM, 0);
    ser.sin_family = AF_INET;
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
    ser.sin_port = htons(22002);
    if(bind(sockid, (struct sockaddr *)&ser, sizeof(ser))<0){
        printf("bind error!\n");
        return 0;
    }
    listen(sockid, 5); // 10 is maximum u can mention any it is the queue limit nonn blocking
    int clientid = accept(sockid, (struct sockaddr *)&cli, &clientlen);
    
    recv(clientid,&D,sizeof(D),0);
    M.max = D.fd1>D.fd2?D.fd1:D.fd2;
    send(clientid,&M,sizeof(M),0);



    close(sockid);
}