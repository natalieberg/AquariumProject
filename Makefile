# program executable name
TARGET = ex6
# compiler flags
CFLAGS = -g -Wall -lcomedi -lrt -pthread -lpthread -D_GNU_SOURCE $(XENO_CFLAGS) -lm
# linker flags
LDFLAGS = -g -lcomedi -lrt -pthread -lpthread -D_GNU_SOURCE $(XENO_LIBS) -lm
# list of sources
SOURCES = $(shell find -name "*.c")
# default rule, to compile everything
all: $(TARGET)
# define object files
OBJECTS = $(SOURCES:.c=.o)
# link programs
$(TARGET): $(OBJECTS)
	gcc -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	gcc -c -o $@ $< $(CFLAGS)
# cleaning
clean:
rm -f $(TARGET) $(OBJECTS) 