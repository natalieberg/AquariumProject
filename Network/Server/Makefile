# program executable name
TARGET = server

# compiler flags
CFLAGS = -g -Wall 

# linker flags
LDFLAGS = -g 

# list of sources
SOURCES = $(shell find -name "*.c")

# default rule, to compile everything
all: $(TARGET)

# define object files
OBJECTS = $(SOURCES:.c=.o)

# link programs
$(TARGET): $(OBJECTS)
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-gcc -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-gcc -c -o $@ $< $(CFLAGS)
# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS) 