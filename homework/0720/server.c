#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 8800
#define BACKLOG 6


int main()
{
	int sfd;	
	if((sfd=socket(AF_INET,SOCK_STREAM,0))==-1){
		puts("create socket error");
		exit(1);
	}
	printf("server socket fd : %d\n",sfd);

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

	//while(1){

	int clfd=accept(sfd,(struct sockaddr *)&conn_addr,(socklen_t *)&con_len);
	printf("kid client ip : %ld\n",conn_addr.sin_addr.s_addr);
	printf("kid client port : %ld\n",ntohl(conn_addr.sin_port));
	printf("p client fd : %d\n",clfd);
	//printf("recieved--->\n");
	pid_t pid;
	if((pid=fork())<0){
		puts("fork error");
		exit(1);
	}else if(pid==0){
		sleep(3);
		printf("kid client fd : %d\n",clfd);
		exit(0);
	}

	//}

	return 0;



	daemon(0,0);
}
