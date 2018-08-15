#include"fd_pass.h"
int send_fd(int sfd,int sendfd)
{
	struct msghdr msg;
	msg.msg_name=NULL;
	msg.msg_namelen=0;

	struct iovec iov;
	char sendchar='\0';
	iov.iov_base=&sendchar;
	iov.iov_len=1;

	msg.msg_iov=&iov;
	msg.msg_iovlen=1;

	struct cmsghdr mhdr;
	mhdr.cmsg_len=CMSG_LEN(sizeof(int));
	mhdr.cmsg_level=SOL_SOCKET;
	mhdr.cmsg_type=SCM_RIGHTS;
	*(int*)CMSG_DATA(&mhdr)=sendfd;

	msg.msg_control=&mhdr;
	msg.msg_controllen=CMSG_LEN(sizeof(int));

	if(sendmsg(sfd,&msg,0)==-1)
		return -sfd;
	return 0;
}

int recv_fd(int sockfd)
{
	struct msghdr msg;
	msg.msg_name=NULL;
	msg.msg_namelen=0;

	struct iovec iov;  
	char recvchar;  
	iov.iov_base = &recvchar;  
	iov.iov_len = 1;  
	msg.msg_iov = &iov;  
	msg.msg_iovlen = 1;

	struct cmsghdr cmsg;  
	msg.msg_control = &cmsg;  
	msg.msg_controllen = CMSG_LEN(sizeof(int)); 

	if (recvmsg(sockfd, &msg, 0) == -1)  
		return -1;  
	return *(int *)CMSG_DATA(&cmsg);
}
