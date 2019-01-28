cxx=gcc
bin=bin/
obj=obj/

#放置在第一位，被标识为最终的目标文件；否则需执行make all
.PHONY:clean

#伪目标
all:ud_server master

#@echo building....
ud_server:ud_server.o fd_pass.o
	$(cxx) -o $(bin)ud_server fd_pass.o ud_server.o

master:fd_pass.o master.o
	$(cxx) -o $(bin)master fd_pass.o master.o

fd_pass.o:fd_pass.h

ud_server.o:fd_pass.h
master.o:fd_pass.h

clean:
	rm -f master
	rm -f ud_server
	rm -f *.o
	
install:

