all: main

LIBS = -L/home/Documents/advanced_algorithms/programming3_advanvedalgorithms/libs/libemon.a
ARGS = -c -std=c++0x

main: Main.o VCAlgorithm.o DimacsReader.o
	$(CXX) -o programming3 *.o $(LIBS)
	
Main.o: ../src/Main.cpp
	$(CXX) ../src/Main.cpp $(ARGS)
	
VCAlgorithm.o: ../src/VCAlgorithm.cpp
	$(CXX) ../src/VCAlgorithm.cpp $(ARGS)
	
DimacsReader.o: ../src/DimacsReader.cpp
	$(CXX) ../src/DimacsReader.cpp $(ARGS)
	
clean:
	rm -f *.o programming3
	
