#include <lemon/list_graph.h>

using namespace lemon;

class VCAlgorithm {
	
	private:
	ListGraph* graph;
	std::vector<ListGraph::Node>* cover;
	clock_t runTime;
	
	ListGraph::Edge randomEdge();
	void removeEdgesOfNode(ListGraph::Node);
	void removeEdge(ListGraph::Edge);
	
	
	public:
	VCAlgorithm(ListGraph*);
	
	int run();
	
	int getRunTime();
	std::vector<ListGraph::Node>* getCover();
	int getCoverSize();
};

