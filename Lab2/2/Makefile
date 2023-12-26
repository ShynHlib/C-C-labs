CC = g++
CFLAGS = -c -Wall -fPIC
LDFLAGS = -L. -lmylibrary -Wl,-rpath,.
SOURCES = Employee.cpp Database.cpp UserInterface.cpp
OBJECTS = $(SOURCES:.cpp=.o)
LIBRARY = libmylibrary.so
EXECUTABLE = main

all: $(SOURCES) $(LIBRARY) $(EXECUTABLE)

$(LIBRARY): $(OBJECTS)
	$(CC) -shared -o $(LIBRARY) $(OBJECTS)

$(EXECUTABLE): UserInterface.o
	$(CC) UserInterface.o -o $(EXECUTABLE) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.so $(EXECUTABLE)

