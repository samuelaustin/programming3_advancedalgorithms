all: main

LIBS = -lemon

main: Main.o VCAlgorithm.o
	$(CXX) -o programming3 *.o $(LIBS)
	
Main.o: ../src/Main.cpp
	$(CXX) ../src/Main.cpp -c
	
VCAlgorithm.o: ../src/VCAlgorithm.cpp
	$(CXX) ../src/VCAlgorithm.cpp -c
	
clean:
	rm -f *.o programming3
	
