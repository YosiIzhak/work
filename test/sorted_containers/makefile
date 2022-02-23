SRC_DIR = ../../src
TEST_DIR  = ../../test/sorted_containers
INC_DIR = ../../inc

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++03

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD)

CPPFLAGS = -I$(INC_DIR)

TARGET = utest
OBJS = utest.o  $(SRC_DIR)/sortedVector.o $(SRC_DIR)/sortedList.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/sortedContainer.hpp $(INC_DIR)/sortedVector.hpp $(INC_DIR)/sortedList.hpp 
$(SRC_DIR)/sortedList.o: $(INC_DIR)/sortedVector.hpp

check: $(TARGET)
	./$(TARGET) -v
	
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean