#include "VCAlgorithm.h"

using namespace lemon;

int main()
{
	std::cout << "Lemons" << "\n";
	
	ListGraph* g = new ListGraph();
	
	
	ListGraph::Node u = g->addNode();
	ListGraph::Node v = g->addNode();
	
	ListGraph::Edge e = g->addEdge(u, v);
	
	VCAlgorithm* alg = new VCAlgorithm(g);
	alg->run();
	
	return 0;
}
