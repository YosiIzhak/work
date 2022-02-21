SRC_DIR = ../../src
TEST_DIR  = ../../test/quick_sort
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
OBJS = utest.o  $(SRC_DIR)/linear_algo.o $(SRC_DIR)/utils.o 

$(TARGET):$(OBJS)

utest.o : $(INC_DIR)/linear_algo.hpp  $(INC_DIR)/utils.hpp 

warpeace:
	wget https://raw.githubusercontent.com/mmcky/nyu-econ-370/master/notebooks/data/book-war-and-peace.txt

book.txt: warpeace
	cat book-war-and-peace.txt| tr -d '[:punct:]' > book.txt

check: $(TARGET)
	./$(TARGET) -v

prod: CXXFLAGS += -O2 -DNDEBUG
prod: $(TARGET)
	./$(TARGET) -v
		
clean:
	@$(RM) $(TARGET) $(OBJS)
	
.PHONY: check clean
