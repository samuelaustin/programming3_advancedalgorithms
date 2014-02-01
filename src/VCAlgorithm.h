#include <lemon/list_graph.h>

using namespace lemon;

class VCAlgorithm {
	
	private:
	ListGraph* graph;
	
	std::vector<ListGraph::Node>* cover;
	std::vector<int> removedEdges;
	clock_t runTime;
	
	int removeEdgesOfNode(ListGraph::Node);
	void removeEdge(ListGraph::Edge);
	
	
	public:
	VCAlgorithm(ListGraph*);
	
	int run();
	ListGraph::Edge randomEdge();
	double getAverageRemovedEdges();
	
	int getRunTime();
	std::vector<ListGraph::Node>* getCover();
	int getCoverSize();
};

