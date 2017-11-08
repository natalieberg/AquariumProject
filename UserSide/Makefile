# program executable name
TARGET = main

# compiler flags
CXXFLAGS = -g -Wall -I/usr/include/cppconn -std=c++11 -pthread

# linker flags
LDFLAGS = -g -L/usr/lib -lmysqlcppconn -std=c++11 -pthread

# list of sources
SOURCES = $(wildcard *.cpp)

# default rule, to compile everything
all: $(TARGET)

# define object files
OBJECTS = $(SOURCES:.cpp=.o)

# link programs
$(TARGET): $(OBJECTS)
	g++ -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	g++ $(CXXFLAGS) -c $@ $< 
# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS) 
