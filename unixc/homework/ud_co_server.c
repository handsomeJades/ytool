#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<bits/socket.h>
#include<netinet/in.h>
#include<string.h>
#include"fd_pass.h"

#define UNIX_DOMIN_PATH "/tmp/test.sock"
#define BACKLOG 6

int main(){
	int sfd=socket(AF_UNIX,SOCK_STREAM,0);

	struct sockaddr_un s_addr;
	s_addr.sun_family=AF_UNIX;
	strcpy(s_addr.sun_path,UNIX_DOMIN_PATH);
	if(connect(sfd,(struct sockaddr *)&s_addr,sizeof(s_addr))==-1){
		perror("connect()");
		exit(1);
	}

	char reponse[11];
	long size=0;
	while(1){
		/*if((size=recv(sfd,reponse,11,0))==-1)
		{
			perror("recv()");
		}*/
		int rfd=recv_fd(sfd);
		printf("received fd= %d\n",rfd);
	}

	return 0;
}
