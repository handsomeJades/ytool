#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>

#define NAME_MAX 255

static	int l_opt=0;
static	int i_opt=0;
static	int opt=0;
static int opt_num=0;

void do_ls(char *);
void show_stat(char *,char *);
void mode_decode(int mode,char mode_str[]);
char *uid2name(uid_t uid);
char *gid2name(gid_t gid);
int main(int argc,char *argv[])
{
		char dir_name[NAME_MAX]=".";
		while((opt=getopt(argc,argv,"il"))!=-1)
		{
				opt_num+=1;
				switch(opt){
						case 'l':
								l_opt=1;
								break;
						case 'i':
								i_opt=1;
								break;
						default:
								break;
				}
		}

		printf("%d,%d,%d,%s\n",l_opt,i_opt,optind,argv[optind]);

		//if(opt_num==0&&argc>1){
		//		strcpy(dir_name,argv[1]);
		//}

		if(optind+1==argc){
				strcpy(dir_name,argv[optind]);
		}
		do_ls(dir_name);
		return 0;
}

void do_ls(char *dir_name)
{
		DIR *dirp;
		struct dirent *direntp;
		if((dirp=opendir(dir_name))==NULL){
				perror("opendir");
		}

		while((direntp=readdir(dirp))){
				//	if(opt_num==0){
				//			printf("%s\t",direntp->d_name);
				//			continue;
				//	}

				//	if(l_opt==1){
				show_stat(dir_name,direntp->d_name);
				//	}
		}

		closedir(dirp);

}

void show_stat(char *dir_name,char *file_name){
		struct stat info;
		char full_path[NAME_MAX];
		char mode_str[11];

		if(strcmp(dir_name,".")==0){
				if(stat(file_name,&info)==-1){
						perror("stat");
						exit(1);
				}
		}else{
				strcpy(full_path,dir_name);
				strcat(full_path,file_name);
				if(stat(full_path,&info)==-1){
						perror("stat");
						exit(1);
				}
		}

		mode_decode(info.st_mode,mode_str);	

		if(i_opt==1) printf("%10ld ",(long)info.st_ino);
		if(l_opt==1){
				printf("%s",mode_str);
				printf("%4d ",(int)info.st_nlink);
				printf("%-8s",uid2name(info.st_uid));
				printf("%-8s",gid2name(info.st_gid));
				printf("%8ld ",(long)info.st_size);
				printf("%.12s ",ctime(&info.st_mtime)+4);
				printf("%s\n",file_name);
				return;
		}
		printf("%s ",file_name);
}		

#include<pwd.h>
char *uid2name(uid_t uid)
{
		struct passwd *pw_p;
		static char numstr[10];
		if((pw_p=getpwuid(uid))==NULL){
				sprintf(numstr,"%d",uid);
				return numstr;
		}

		return pw_p->pw_name;
}
#include<grp.h>
char *gid2name(gid_t gid)
{
		struct group *grp_p;
		static char numstr[10];
		if((grp_p=getgrgid(gid))==NULL){
				sprintf(numstr,"%d",gid);
				return numstr;
		}

		return grp_p->gr_name;
}



void mode_decode(int mode,char mode_str[]){
		strcpy(mode_str,"----------.");

		if(S_ISDIR(mode)){
				mode_str[0]='d';
		}
		if(S_ISCHR(mode)){
				mode_str[0]='c';
		}
		if(S_ISBLK(mode)){
				mode_str[0]='b';
		}


		if(S_IRUSR&mode){
				mode_str[1]='r';
		}
		if(S_IWUSR&mode){
				mode_str[2]='w';
		}
		if(S_IXUSR&mode){
				mode_str[3]='x';
		}

		if(S_IRGRP&mode){
				mode_str[4]='r';
		}
		if(S_IWGRP&mode){
				mode_str[5]='w';
		}
		if(S_IXGRP&mode){
				mode_str[6]='x';
		}


		if(S_IROTH&mode){
				mode_str[7]='r';
		}
		if(S_IWOTH&mode){
				mode_str[8]='w';
		}
		if(S_IXOTH&mode){
				mode_str[9]='x';
		}

}












