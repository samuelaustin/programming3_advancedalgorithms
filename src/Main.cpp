#include <lemon/list_graph.h>

using namespace lemon;

int main()
{
	std::cout << "Lemons" << "\n";
	
	ListGraph g;
	
	ListGraph::Node u = g.addNode();
	ListGraph::Node v = g.addNode();
	
	ListGraph::Edge e = g.addEdge(u, v);
	
	return 0;
}
