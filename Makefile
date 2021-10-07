CXX = g++
FLAGS = -std=c++20 -O3 -march=native -Wall -Wextra -pedantic

default:
	$(CXX) $(FLAGS) -c Example.cpp
