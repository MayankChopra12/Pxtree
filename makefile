# The following just specifies some variables for "flexibility".

# Specify the C++ compiler
CXX     = g++

# Specify options to pass to the compiler. Here it sets the optimisation
# level, outputs debugging info for gdb, and C++ version to use.
CXXFLAGS = -O0 -g3 -std=c++14

All: all
all: main PxtreeTesterMain

main: main.cpp Pxtree.o
	$(CXX) $(CXXFLAGS) main.cpp Pxtree.o -o main

# The -c command produces the object file
Pxtree.o: Pxtree.cpp Pxtree.h
	$(CXX) $(CXXFLAGS) -c Pxtree.cpp -o Pxtree.o

PxtreeTesterMain: PxtreeTesterMain.cpp Pxtree.o PxtreeTester.o
	$(CXX) $(CXXFLAGS) PxtreeTesterMain.cpp Pxtree.o PxtreeTester.o -o PxtreeTesterMain

PxtreeTester.o: PxtreeTester.cpp PxtreeTester.h	
	$(CXX) $(CXXFLAGS) -c PxtreeTester.cpp -o PxtreeTester.o

# Some cleanup functions, invoked by typing "make clean" or "make deepclean"
deepclean: 
	rm -f *~ *.o main *.exe *.stackdump

clean:
	rm -f *~ *.o *.stackdump

