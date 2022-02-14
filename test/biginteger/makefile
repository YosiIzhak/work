CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++03

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD)

CPPFLAGS = -I$(INC_DIR)

INC_DIR = ../../inc

TARGET = utest
OBJS = utest.o ../../src/biginteger.o ../../src/single_list.o ../../src/hashset.o

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

debug: $(TARGET)
	valgrind --leak-check=full ./${TARGET} -v
	gdb -q ${TARGET}

vala: $(TARGET)
	valgrind --log-file=V1.log ./$(TARGET)
	valgrind --log-file=V2.log --leak-check=full --track-origins=yes ./$(TARGET)		
clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: clean check

