SRC_DIR = ../../exams/e02
TEST_DIR  = ../../exams/e02
INC_DIR = ../../exams/e02

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++03


CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = utest
OBJS = utest.o store.o 

$(TARGET):$(OBJS)

utest.o :store.hpp 


check: $(TARGET)
	./$(TARGET) -v


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean