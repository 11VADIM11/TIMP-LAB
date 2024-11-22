# Установим переменные
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = -lUnitTest++

# Исходные файлы
SRC_MAIN = main.cpp modGRONSFELD.cpp
SRC_TEST = test_modGRONSFELD.cpp modGRONSFELD.cpp
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)
OBJ_TEST = $(SRC_TEST:.cpp=.o)

# Исполняемые файлы
TARGET_MAIN = chiper_main
TARGET_TEST = chiper_test

# Правила по умолчанию
all: $(TARGET_MAIN) $(TARGET_TEST)

# Линковка основного исполняемого файла
$(TARGET_MAIN): $(OBJ_MAIN)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Линковка исполняемого файла с тестами
$(TARGET_TEST): $(OBJ_TEST)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Компиляция объектных файлов
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Чистка временных файлов
clean:
	rm -f $(OBJ_MAIN) $(TARGET_MAIN) $(OBJ_TEST) $(TARGET_TEST)

.PHONY: all clean
