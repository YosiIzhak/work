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
	

#PATH_SOURCE = ../../src
#PATH_TESTSTACK = ../../test/cstack
#PATH_HEADER =../../inc

#TARGET= stack.out
#CC= g++
#CFLAGS= -ansi -pedantic -g
#OBJS= cstack.o cstackTest.o 

#$(TARGET):$(OBJS)
#	$(CC) -o $(TARGET) $(OBJS) 

#cstack.o:$(PATH_SOURCE)/cstack.c $(PATH_HEADER)/cstack.h 
#	$(CC) $(CFLAGS) -c -I$(PATH_HEADER) $(PATH_SOURCE)/cstack.c 

#cstackTest.o:$(PATH_TESTSTACK)/cstackTest.c $(PATH_HEADER)/cstack.h $(PATH_HEADER)/mu_test.h
#	$(CC) $(CFLAGS) -c -I$(PATH_HEADER) -I$(PATH_HEADER) $(PATH_TESTSTACK)/cstackTest.c

#chack: $(TARGET)
#	./$(TARGET) -v
	
#clean:
#	@$(RM) $(TARGET) $(OBJS)
	
#.PHONY: chack clean


	
	
