#include <lemon/list_graph.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace lemon;

class DimacsReader {
	
	private:
	int nodes;
	int edges;
	ListGraph g;
	
	public:
	DimacsReader();
	ListGraph* readFile(std::string);
	
	int numberOfNodes();
	int numberOfEdges();
	
	private:
	void processFirstLine(std::string);
	void readEdge(std::string);
};

