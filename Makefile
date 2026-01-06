CXX = g++
CXXFLAGS = -Wall -Wextra -o2

TARGET = matrix
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f  $(TARGET)