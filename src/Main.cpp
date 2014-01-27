#include "VCAlgorithm.h"
#include "DimacsReader.h"

using namespace lemon;

int main()
{
	/*
	ListGraph* g = new ListGraph();
	
	
	ListGraph::Node a = g->addNode();
	ListGraph::Node b = g->addNode();
	ListGraph::Node c = g->addNode();
	ListGraph::Node d = g->addNode();
	ListGraph::Node e = g->addNode();
	ListGraph::Node u = g->addNode();
	ListGraph::Node v = g->addNode();
	
	ListGraph::Edge e1 = g->addEdge(u, v);
	ListGraph::Edge e2 = g->addEdge(a, v);
	ListGraph::Edge e3 = g->addEdge(b, c);
	ListGraph::Edge e4 = g->addEdge(b, e);
	ListGraph::Edge e5 = g->addEdge(e, u);
	ListGraph::Edge e6 = g->addEdge(c, d);
	ListGraph::Edge e7 = g->addEdge(d, u);
	
	std::cout << "Number of edges: " << countEdges(*g) << "\n";
	*/
	
	//VCAlgorithm* alg = new VCAlgorithm(g);
	/*
	std::cout << "Printing random edge id..." << "\n";
	std::srand(time(0));
	for(int i = 0; i < 10; i++)
	{
		std::cout << g->id(alg->randomEdge()) << "\n";
	}
	std::cout << "\n";
	*/
	
	/*
	alg->run();
	std::cout << "Size of cover: " << alg->getCoverSize() << "\n";
	std::cout << "Run Time: " << alg->getRunTime() << "\n";
	*/
	
	std::string file = "../files/frb30-15-mis/frb30-15-1.mis";
	
	DimacsReader* reader = new DimacsReader();
	reader->readFile(file);
	
	return 0;
}
