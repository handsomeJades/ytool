#include <stdio.h>          /* These are the usual header files */

#include <string.h>         /* for bzero() */

#include <unistd.h>         /* for close() */

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <sys/time.h>

#include <stdlib.h>



#define PORT 6888   /* Port that will be opened */

#define BACKLOG 5   /* Number of allowed connections simutaniously*/

#define MAXDATASIZE 1000



typedef struct _CLIENT{

	int    fd;

	struct sockaddr_in addr; /* client's address information */

	char   data[1024]; 

}CLIENT;



void process_cli(CLIENT *client, char* recvbuf, int len);

void savedata(char* recvbuf, int len, char* data); 



main()

{

	int    i, maxi, maxfd, sockfd;

	int    nready;

	size_t n;

	fd_set rset, allset;

	int listenfd, connectfd;   /* socket descriptors */    

	struct sockaddr_in server; /* server's address information */



	/* client's information */

	CLIENT client[FD_SETSIZE];

	char recvbuf[MAXDATASIZE];

	int sin_size;



	/* Create TCP socket  */

	if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){

		/* handle exception */

		perror("Creating socket failed.");

		exit(1);

	}



	int opt = SO_REUSEADDR;

	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	bzero(&server,sizeof(server));

	server.sin_family=AF_INET;

	server.sin_port=htons(PORT);

	server.sin_addr.s_addr = htonl (INADDR_ANY);

	if( bind(listenfd, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1 ){

		/* handle exception */

		perror("Bind error.");

		exit(1);

	}



	if(listen(listenfd,BACKLOG) == -1){  /* calls listen() */

		perror("listen() error\n");

		exit(1);

	}

	sin_size = sizeof(struct sockaddr_in);





	/*initialize for select */

	maxfd = listenfd;

	maxi = -1;   

	for( i = 0; i<FD_SETSIZE; i++ ){

		client[i].fd = -1;  

	}



	FD_ZERO( &allset );

	FD_SET( listenfd, &allset );

	while(1){

		struct sockaddr_in addr;

		rset = allset;            

		nready = select( maxfd+1, &rset, NULL, NULL, NULL );

		printf("select saw rset actions and the readfset num is %d. \n",nready );

		if( FD_ISSET(listenfd, &rset) ){

			/* new client connection */

			/* Accept connection */

			printf("accept a connection.\n");

			if(( connectfd = accept(listenfd,(struct sockaddr *)&addr,(socklen_t *)&sin_size))==-1 ){

				perror("accept() error\n");

				continue;

			}



			/* Put new fd to client */

			for( i = 0; i < FD_SETSIZE; i++ ){

				if (client[i].fd < 0) {

					client[i].fd = connectfd;    /* save descriptor */

					client[i].addr = addr;

					client[i].data[0] = '\0';

					printf("You got a connection from %s.  ",inet_ntoa(client[i].addr.sin_addr) );

					break;

				}

			}



			printf("add new connect fd.\n");

			if(i == FD_SETSIZE ) printf("too many clients\n");

			FD_SET( connectfd, &allset );   /* add new descriptor to set */

			if( connectfd > maxfd ) maxfd = connectfd;   

			if( i > maxi ) maxi = i;          

			if( --nready <= 0 ) continue; /* no more readable descriptors */

		}



		for( i = 0; i <= maxi; i++ ){     

			/* check all clients for data */

			if( (sockfd = client[i].fd) < 0 ) continue; /* no more connected clients*/

			if( FD_ISSET(sockfd, &rset) ){

				printf( "recv occured for connect fd[%d].\n",i );

				if( (n = recv(sockfd, recvbuf, MAXDATASIZE,0) ) == 0 ){

					/*connection closed by client */

					close(sockfd);

					printf("Client( %d ) closed connection.\n",client[i].fd );

					FD_CLR(sockfd, &allset);

					client[i].fd = -1;

				}

				else{

					process_cli( &client[i], recvbuf, n );

				}

				if (--nready <= 0)     break;      /* no more readable descriptors */

			}

		}



	}

	close(listenfd);   /* close listenfd */        

}



void process_cli( CLIENT *client, char* recvbuf, int len )

{

	send( client->fd, recvbuf, len, 0 );

}
