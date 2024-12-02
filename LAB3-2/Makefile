CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include

SRC = main.cpp modRoutePermutation.cpp
TEST_SRC = test_modRoutePermutation.cpp
OBJ = $(SRC:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)

all: main

main: $(OBJ)
	$(CXX) -o main $(OBJ)

test: $(OBJ) $(TEST_OBJ)
	$(CXX) -o test_modRoutePermutation $(TEST_OBJ) modRoutePermutation.o -lUnitTest++
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TEST_OBJ) main test_modRoutePermutation
