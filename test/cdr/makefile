

CC := $(CXX)

CXX := g++

CPPFLAGS = -I../inc -I../../inc -I./inc

WARNS = -Wall -Werror -pedantic

CXXFLAGS = -std=c++17 $(WARNS)

CXXFLAGS += -g

LDLIBS   = -lpthread

OBJS   := utest.o fields.o cdr.o

TARGET := utest

all: $(TARGET)

$(TARGET): $(OBJS)

fields.o: fields.hpp 

cdr.o: fields.hpp cdr.hpp data_type.hpp

check: all

    @./$(TARGET) -v

debug: $(TARGET)

    $(VALGRIND) ./$(TARGET) -v

valgrind: $(TARGET)

    valgrind --leak-check=full --track-origins=yes --log-file=logValgrind01.txt ./$(TARGET)

    valgrind --tool=helgrind --log-file=loghelgrind01.txt ./$(TARGET)

    valgrind --tool=drd --log-file=logdrd01.txt ./$(TARGET)

clean:

    $(RM) $(TARGET) $(OBJS)

.PHONY: all run clean valgrind

