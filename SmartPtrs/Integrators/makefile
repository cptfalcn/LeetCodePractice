CC=	g++ 
CFLAGS=	-g	-Wall	-std=c++17	-O0
TARGET	=	Integrator.x
OBJECTS	=	Tests.o Integrator.o Problem.o
BUILD ?=	debug
##Make the build tree 
ifeq ($(BUILD), debug)
	CFLAGS=	-g	-Wall	-std=c++17	-O0 -pedantic
else ifeq ($(BUILD), release)
	CFLAGS=	-DNDEBUG 	-Wall	-std=c++17	-O3 -pedantic
else
    $(error unknown build type: $(BUILD))
endif

##compile and linking
all: $(TARGET)
Integrator.x:	Tests.o Integrator.o Problem.o
	$(CC)	$(CFLAGS)	$(OBJECTS)	-o	$(TARGET)
Tests.o: Tests.cpp Integrator.h
	$(CC)	$(CFLAGS)	-c	Tests.cpp
Problem.o: Problem.cpp Problem.h
	$(CC)	$(CFLAGS)	-c	Problem.cpp
Integrator.o: Integrator.cpp Integrator.h Problem.h
	$(CC)	$(CFLAGS)	-c	Integrator.cpp


##Commands
.PHONEY:	clean
clean:
	rm $(TARGET) $(OBJECTS)
run: 
	./$(TARGET)
debug:
	@$(MAKE) all BUILD=debug
release:
	@$(MAKE) all BUILD=release
