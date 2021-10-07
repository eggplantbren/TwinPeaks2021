CXX = g++
FLAGS = -std=c++20 -O3 -march=native -Wall -Wextra -pedantic

default:
	$(CXX) $(FLAGS) -c Context.cpp
	$(CXX) $(FLAGS) -c Example.cpp
	ar rcs libTwinPeaks2021.a *.o
	$(CXX) $(FLAGS) -c main.cpp
	$(CXX) -L . -o main main.o -lTwinPeaks2021
	rm -rf *.o
