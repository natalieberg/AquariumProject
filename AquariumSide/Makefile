# program executable name
TARGET = main

# compiler flags
CXXFLAGS = -g -Wall -I/home/natalie/wiringPi/wiringPi -std=c++11 -pthread  

# linker flags
LDFLAGS = -g -L/home/natalie/wiringPi/wiringPi -lwiringPi -std=c++11 -pthread 

# list of sources
SOURCES = $(wildcard *.cpp)

# default rule, to compile everything
all: $(TARGET)

# define object files
OBJECTS = $(SOURCES:.c=.o)

# link programs
$(TARGET): $(OBJECTS)
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-g++ -o $@ $^ $(LDFLAGS)
# compile
%.o : %.c
	/home/natalie/AquariumProjectGit/AquariumProject/x-tools/arm-rpi-linux-gnueabi/bin/arm-rpi-linux-gnueabi-g++ -c -o $@ $< $(CXXFLAGS)
# cleaning
clean:
	rm -f $(TARGET) $(OBJECTS) 
