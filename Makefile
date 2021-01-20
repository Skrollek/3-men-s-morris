CXX = g++
CXXFLAGS = -O2 -H -std=c++17 -Wall
OBJ = main.o 
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

PCH_SRC = source/pch.hpp
#PCH_HEADERS = 
PCH_OUT = source/pch.hpp.gch

all: clean $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o 3mensMorris $(SFML)
main.o: 
	@g++ -c main.cpp
clean:
	@rm -f $(OBJ) 
	@rm -f 3mensMorris
pre:
	@$(CXX) $(CXXFLAGS) $(PCH_SRC);
	@make
	
	

