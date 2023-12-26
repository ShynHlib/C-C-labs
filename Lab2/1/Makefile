CC = g++
CFLAGS = -c -Wall
LDFLAGS = -L. -lmylibrary
SOURCES = Employee.cpp Database.cpp UserInterface.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = libmylibrary.a
EXECUTABLE = main

all: $(SOURCES) $(LIBRARY) $(EXECUTABLE)

$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

$(EXECUTABLE): UserInterface.o
	$(CC) UserInterface.o -o $(EXECUTABLE) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.a $(EXECUTABLE)

