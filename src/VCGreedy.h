#include <lemon/list_graph.h>

using namespace lemon;

class VCGreedy {
	
	private:
	ListGraph* graph;
	
	std::vector<ListGraph::Node>* cover;
	clock_t runTime;
	
	void removeEdgesOfNode(ListGraph::Node);
	void removeEdge(ListGraph::Edge);
	
	
	public:
	VCGreedy(ListGraph*);
	
	int run();
	ListGraph::Edge GreedyEdge();
	
	int getRunTime();
	std::vector<ListGraph::Node>* getCover();
	int getCoverSize();
};

