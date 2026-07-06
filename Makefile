CXX = g++
CXXFLAGS = -Iinclude -std=c++11

SRC = src/main.cpp src/Book.cpp src/Library.cpp
TARGET = Library

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	del /Q Library.exe