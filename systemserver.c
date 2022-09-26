#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <error.h>
#include <sys/types.h>
#include <netinet/in.h>
int max(short x,short y){
    return x>y?x:y;
}
int main(){
      pid_t childid;
      int id=socket(AF_INET,SOCK_STREAM,0);
      struct sockaddr_in serv,udp;
      bzero(&serv,sizeof(serv));
      serv.sin_addr.s_addr=htonl('127.0.0.1');
      serv.sin_family=AF_INET;
      serv.sin_port=htons(8088);
      int uid=socket(AF_INET,SOCK_DGRAM,0);
      bind(id,(struct sockaddr *)&serv,sizeof(serv));
      listen(id,10);
      bind(uid,(struct sockaddr *)&serv,sizeof(serv));
      fd_set rset;
      int maxfd=max(id,uid);
      void sig_chld(int);
      FD_ZERO(&rset);
      for(;;){
      FD_SET(id,&rset);
      FD_SET(uid,&rset);}
      int nready=select(maxfd,&rset,NULL,NULL,NULL);
      if(FD_ISSET(id,&rset)){
        socklen_t len=sizeof(udp);
        int confd=accept(id,(struct sockaddr *)&udp,&len);
        if((childid==fork())){
            close(id);
            
        }
      }









}