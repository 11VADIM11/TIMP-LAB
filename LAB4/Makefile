CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Werror
LDFLAGS = -lstdc++fs


TARGET = cipher


SRCS = main.cpp modGronsfeld.cpp


$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)


.PHONY: all clean
all: $(TARGET)
