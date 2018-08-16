#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>
#include"fd_pass.h"

#define PORT 8080
#define BACKLOG 6

int main()
{
		int sfd;	
		if((sfd=socket(AF_INET,SOCK_STREAM,0))==-1){
				puts("create socket error");
				exit(1);
		}
		//	printf("server socket fd : %d\n",sfd);

		struct sockaddr_in serv_addr,conn_addr;
		memset(&serv_addr,0,sizeof(struct sockaddr_in));
		serv_addr.sin_family=AF_INET;
		serv_addr.sin_port=htons(PORT);
		serv_addr.sin_addr.s_addr=htons(INADDR_ANY);

		if(bind(sfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr_in))==-1){
				puts("bind error");
				exit(1);
		}


		int con_len=sizeof(struct sockaddr_in);
		if(listen(sfd,BACKLOG)==-1){
				puts("listen error");
				exit(1);
		}

		int ufd=socket(AF_UNIX,SOCK_STREAM,0);

		//unix domin socket
		struct sockaddr_un s_addr;
		s_addr.sun_family=AF_UNIX;
		strcpy(s_addr.sun_path,UNIX_DOMIN_PATH);
		if(connect(ufd,(struct sockaddr *)&s_addr,sizeof(s_addr))==-1){
				perror("connect()");
				exit(1);
		}

		int clfd;
		while(1){
				clfd=accept(sfd,(struct sockaddr *)&conn_addr,(socklen_t *)&con_len);
				//int len = recv(clfd,buf,sizeof(buf),0);
				//				send(clfd,msg,strlen(msg),0);
				printf("ufd=%d,clfd=%d\n",ufd,clfd);
				if(send_fd(ufd,clfd)<0)
				{
					perror("send_fd()");
				}
				//close(clfd);
		}



		return 0;



		daemon(0,0);
}
