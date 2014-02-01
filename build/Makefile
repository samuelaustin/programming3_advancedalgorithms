all: main

INCL = -I ../include/
LIBS = -L ../libs/libemon.a
ARGS = -c -std=c++0x

main: Main.o VCAlgorithm.o VCGreedy.o VCGreedyImproved.o DimacsReader.o
	$(CXX) -o programming3 *.o $(LIBS) $(INCL)
	
Main.o: ../src/Main.cpp
	$(CXX) ../src/Main.cpp $(ARGS) $(INCL)
	
VCAlgorithm.o: ../src/VCAlgorithm.cpp
	$(CXX) ../src/VCAlgorithm.cpp $(ARGS) $(INCL)
	
VCGreedy.o: ../src/VCGreedy.cpp
	$(CXX) ../src/VCGreedy.cpp $(ARGS) $(INCL)

VCGreedyImproved.o: ../src/VCGreedyImproved.cpp
	$(CXX) ../src/VCGreedyImproved.cpp $(ARGS) $(INCL)

DimacsReader.o: ../src/DimacsReader.cpp
	$(CXX) ../src/DimacsReader.cpp $(ARGS) $(INCL)
	
clean:
	rm -f *.o programming3
	
