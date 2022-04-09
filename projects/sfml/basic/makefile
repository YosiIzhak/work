SRC_DIR = ../../projects/sfml/basic
TEST_DIR  = ../../projects/sfml/basic
INC_DIR = ../../projects/sfml/basic

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
OBJS = ./main.o  ./ball.o ./rectangle.o ./paddle.o ./collision.o ./level.o ./game.o

$(TARGET):$(OBJS)

main.o :
ball.o : ./ball.hpp 
rectangle.o: ./rectangle.hpp
paddle.o: ./paddle.hpp
collision: ./collision.hpp
level: ./level.hpp
game: ./game.hpp

check: $(TARGET)
	./$(TARGET) -v  


clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: check clean