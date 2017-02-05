SOURCES=$(wildcard *.cpp)
CC=g++
CFLAGS=-c -Wall -Wpedantic -std=c++11
LDFLAGS=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $*.cpp 

clean:
	rm *.o $(EXECUTABLE)