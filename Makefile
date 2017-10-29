SRC = game.cpp
OBJS = $(SRC:.cpp=.o)

OBJ_NAME = SDLgame



#compiler flags
COMPILER_FLAGS = -Wall -std=c++14

#libraries linked
LINKER_FLAGS = -lSDL2 -lSDL2_image

all : $(OBJS)
	$(CXX) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJS)