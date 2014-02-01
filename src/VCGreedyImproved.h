#include <lemon/list_graph.h>
#include <lemon/concepts/graph.h>

using namespace lemon;

class VCGreedyImproved {
	
	private:
	bool reverse;
	ListGraph* graph;
	ListGraph::NodeMap<int> *nmap;
	ListGraph::EdgeMap<int> *emap;
	std::vector<ListGraph::Edge>* elist;
	std::vector<ListGraph::Node>* nlist;
	clock_t runTime;
	
	void removeEdgesOfNode(ListGraph::Node);
	void removeEdge(ListGraph::Edge);

	//bool sortDegree(ListGraph::Edge, ListGraph::Edge);
	int getDegree(ListGraph::Edge);
	
	
	public:
	VCGreedyImproved(ListGraph* g, bool r = false);
	int run();
	ListGraph::Edge GreedyEdge();
	
	int getRunTime();
	int getCoverSize();
	void prune_set();
};

