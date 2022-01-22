PATH_STACK = /home/yosi/work/src
PATH_TESTSTACK =  /home/yosi/work/test
PATH_H_FILES =  /home/yosi/work/inc

TARGET= stack.out
CC= g++
CFLAGS= -ansi -pedantic -g
OBJS= stack.o stacktest.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) 

$(PATH_STACK)/stack.o: $(PATH_STACK)/stack.c $(PATH_H_FILES)/stack.h 
	$(CC) $(CFLAGS) -c $(PATH_STACK)/stack.c 

stacktest.o: $(PATH_TESTSTACK)/cstack/stacktest.c $(PATH_H_FILES)/stack.h $(PATH_TESTSTACK)/mu_test.h
	$(CC) $(CFLAGS) -c  stacktest.c

clean:
	rm -f $(TARGET) $(OBJS)
	


	
	
