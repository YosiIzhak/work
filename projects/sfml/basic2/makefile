SRC_DIR = ../../projects/sfml/basic2
TEST_DIR  = ../../projects/sfml/basic2
INC_DIR = ../../projects/sfml/basic2

CXX = g++
CC = $(CXX)

WARNINGS = -pedantic
WARNINGS += -Wall -Werror

DEBUG = -g3
CXX_STD = c++17

LDLIBS   = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CXXFLAGS = $(WARNINGS) $(DEBUG) -std=$(CXX_STD) $(LDLIBS)


CPPFLAGS = -I$(INC_DIR)

TARGET = main
OBJS = ./main.o  ./ball.o ./brick.o ./paddle.o ./collision.o ./level.o ./game.o

$(TARGET):$(OBJS)

main.o :
ball.o : ./ball.hpp 
brick.o: ./brick.hpp
paddle.o: ./paddle.hpp
collision: ./collision.hpp
level: ./level.hpp
game: ./game.hpp

check: $(TARGET)
	./$(TARGET) -v  


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean