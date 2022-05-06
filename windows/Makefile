CC = cc
CFLAGS = -pedantic -Wall
TARGET = simple-cpp-xml-parser
OBJECTS = main.o

all: $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	rm -f *.o $(TARGET)

