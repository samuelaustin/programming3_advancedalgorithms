#include <ctime>
#include "VCGreedy.h"

using namespace lemon;

VCGreedy::VCGreedy(ListGraph* g)
{
	graph = g;
	cover = new std::vector<ListGraph::Node>();
}

int VCGreedy::run()
{
	clock_t start = clock();
	
	//Perform algorithm while there are still edges in the graph
	while(countEdges(*graph) > 0)
	{
		//Choose a random edge
		ListGraph::Edge e = GreedyEdge();
		
		ListGraph::Node u = graph->u(e);
		ListGraph::Node v = graph->v(e);
		
		//Add its nodes to the cover
		cover->push_back(u);
		cover->push_back(v);
		
		
		//Remove all edges of the added nodes
		removeEdge(e);
		removeEdgesOfNode(u);
		removeEdgesOfNode(v);
	}
	
	clock_t end = clock();
	
	runTime = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
	return runTime;
}

ListGraph::Edge VCGreedy::GreedyEdge()
{
	ListGraph::Edge best;
	int largestCount = -1;
	ListGraph::EdgeIt it(*graph);
	while(it!=INVALID)
	{
		ListGraph::Node u = graph->u(it);
		ListGraph::Node v = graph->v(it);
		
		int edges = countIncEdges(*graph, u) + countIncEdges(*graph, v);
		
		if(edges > largestCount)
		{
			largestCount = edges;
			best = it;
		}
		++it;
	}
	
	return best;
}

void VCGreedy::removeEdge(ListGraph::Edge e)
{
	graph->erase(e);
}

void VCGreedy::removeEdgesOfNode(ListGraph::Node n)
{
	graph->erase(n);
	/*
	for(ListGraph::EdgeIt it(*graph); it != INVALID; ++it)
	{
		if(graph->u(it) == n || graph->v(it) == n)
		{
			graph->erase(it);
		}
	}
	*/
}

int VCGreedy::getRunTime()
{
	return runTime;
}

int VCGreedy::getCoverSize()
{
	return cover->size();
}

std::vector<ListGraph::Node>* VCGreedy::getCover()
{
	return cover;
}

