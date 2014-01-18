all: main

LIBS = -lemon

main: Main.o
	$(CXX) -o programming3 *.o $(LIBS)
	
Main.o: ../src/Main.cpp
	$(CXX) ../src/Main.cpp -c
	
clean:
	rm -f *.o programming3
	
