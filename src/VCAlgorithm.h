#include <lemon/list_graph.h>

using namespace lemon;

class VCAlgorithm {
	
	private:
	ListGraph* graph;
	std::vector<ListGraph::Edge> edges;
	
	std::vector<ListGraph::Node>* cover;
	clock_t runTime;
	
	void removeEdgesOfNode(ListGraph::Node);
	void removeEdge(ListGraph::Edge);
	
	
	public:
	VCAlgorithm(ListGraph*);
	
	int run();
	ListGraph::Edge randomEdge();
	
	int getRunTime();
	std::vector<ListGraph::Node>* getCover();
	int getCoverSize();
};

