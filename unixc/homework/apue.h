#ifndef _APUE_H
#define _APUE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>


/*error handle function*/
void error_sys(const char *,...);



#define MAXLINE 4096	/*max line length*/
#endif
