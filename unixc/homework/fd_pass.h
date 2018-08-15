#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<bits/socket.h>
#include<netinet/in.h>
#include<string.h>

#define UNIX_DOMIN_PATH "/tmp/test.sock"
#define BACKLOG 6

int send_fd(int,int);
int recv_fd(int);
