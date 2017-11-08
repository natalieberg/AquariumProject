# program executable name
TARGET = readTemp

# compiler flags
CFLAGS = -g -Wall 

# linker flags
LDFLAGS = -g 

# list of sources
SOURCES = $(shell find -name "*.cpp")

# default rule, to compile everything
all: $(TARGET)

# define object files
OBJECTS = $(SOURCES:.c=.o)

# link programs
$(TARGET): $(OBJECTS)
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-g++ -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-g++ -c -o $@ $< $(CFLAGS)
# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS) 
