# Compiler
COMPILER  = g++

# compile arguments
CFLAGS = `pkg-config --cflags opencv` -Ipthread 

# linking arguments
LIBS = `pkg-config --libs opencv` -lpthread

# source files
SRCS = main.cpp \
	   vetdetectorcontext.cpp \
	   vetdetectorstrategy.cpp \
	   vethaardetector.cpp \
	   vetimagetoolkit.cpp \
	   vettester.cpp \
	   vetfastvideocapture.cpp \
	   vetconcurrentqueue.cpp

# object files
OBJS = $(SRCS:.cpp=.o)

# name of the executable
TARGET = launch

# Link object file and generate exec file
$(TARGET): $(OBJS)
	$(COMPILER) $^ -o $@ $(LIBS)

# Compile all source files
%.o: %.cpp
	$(COMPILER) $(CFLAGS) -o $@ -c $^

# Generate the exec file (if necessary) and launch it
run: $(TARGET)
	./$(TARGET)

# Clean up exec file and all object files
clean:
	rm -f $(TARGET) $(OBJS)
	rm -f *.o

# Refresh the exec file and all object files
refresh: clean $(TARGET)
	./$(TARGET)

haarDemo: haarDemo.o
	$(COMPILER) $^ -o $@ $(LIBS)
