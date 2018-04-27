# This is where our files are located
PROJECTNAME=mvInterProcessTester
BUILDFOLDER=bin

SRCDIR=src
INC_DIRS= -I inc
LIB_DIR= -L../lib/$(TARGET)

CPPSRC= $(wildcard $(SRCDIR)/*.cpp)

CFLAGS= -W -Wall -D LINUX_PLATFORM -std=c++11 -fPIC -Wno-unused-parameter

LDFLAGS= -lpthread

CPPFILES= $(CPPSRC:.cpp=.o)
vpath %.o $(BUILDFOLDER)/$(TARGET)
vpath %.cpp ./src

.PHONY: all debug build clean rebuild

# Build release default configuration
all: TARGET=release
all: createFolder build

# Build debug
debug: CFLAGS += -g -D _DEBUG
debug: TARGET=debug
debug: createFolder build

# Rebuild 
rebuild: createFolder clean build

createFolder:
	mkdir -p $(BUILDFOLDER)
	mkdir -p $(BUILDFOLDER)/$(TARGET)

# Build
build: $(notdir $(CPPFILES)) 
	$(CC) $(addprefix $(BUILDFOLDER)/$(TARGET)/, $^) $(LIB_DIR) $(LDFLAGS) -o $(BUILDFOLDER)/$(TARGET)/$(PROJECTNAME).exe
	
%.o: %.cpp
	$(CC) -o $(BUILDFOLDER)/$(TARGET)/$(notdir $@) -c $(INC_DIRS) $< $(CFLAGS)

# Clean
clean:
	rm -rf $(BUILDFOLDER)
