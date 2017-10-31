SRC = game.cpp $(wildcard sprite/*.cpp)
OBJS = $(SRC:.cpp=.o)

OBJ_NAME = SDLgame



#compiler flags
COMPILER_FLAGS = -g -Wall -std=c++14

#libraries linked
LINKER_FLAGS = -lSDL2 -lSDL2_image

%.o : %.cpp
	$(CXX) $(COMPILER_FLAGS) $< -c -o $@
all : $(OBJS)
	$(CXX) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJS)
