CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I/usr/include/UnitTest++
TARGET = modGRONSFELD
TEST_TARGET = test_modGRONSFELD

SRCS = modGRONSFELD.cpp main.cpp
TEST_SRCS = test_modGRONSFELD.cpp modGRONSFELD.cpp

.PHONY: all clean test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRCS)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) -o $(TEST_TARGET) -lUnitTest++

clean:
	rm -f $(TARGET) $(TEST_TARGET)
