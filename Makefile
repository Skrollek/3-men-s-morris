CXX = g++
CXXFLAGS = -O2 -std=c++17 -Wall
OBJ = main.o pawn.o 
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

INC_DIR=.
SRC_DIR=.

NAME=3mensMorris

all: $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME) $(SFML)
%.o: $(SRC_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c -I$(INC_DIR) $< -o $@
clean:
	@rm -f $(NAME) $(OBJ)
