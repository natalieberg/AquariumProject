# program executable name
TARGET = sql

# compiler flags
CFLAGS = -g -Wall -I/usr/include/cppconn

# linker flags
LDFLAGS = -g -L/usr/lib -lmysqlcppconn

# list of sources
SOURCES = $(shell find -name "*.cpp")

# default rule, to compile everything
all: $(TARGET)

# define object files
OBJECTS = $(SOURCES:.c=.o)

# link programs
$(TARGET): $(OBJECTS)
	g++ -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	g++ -c -o $@ $< $(CFLAGS)
# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS) 
