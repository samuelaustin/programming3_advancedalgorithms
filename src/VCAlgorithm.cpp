#include <ctime>
#include "VCAlgorithm.h"

using namespace lemon;

VCAlgorithm::VCAlgorithm(ListGraph* g)
{
	graph = g;
	cover = new std::vector<ListGraph::Node>();
}

int VCAlgorithm::run()
{
	std::cout << "Starting Algorithm..." << "\n";
	clock_t start = clock();
	
	//Perform algorithm while there are still edges in the graph
	while(countEdges(*graph) > 0)
	{
		//Choose a random edge
		ListGraph::Edge e = randomEdge();
		
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
	std::cout << "Algorithm Completed" << "\n";
	
	runTime = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
	return runTime;
}

ListGraph::Edge VCAlgorithm::randomEdge()
{
	int n = countEdges(*graph);
	int k = std::rand() % n;
	
	ListGraph::EdgeIt it(*graph);
	int count = 0;
	while(it!=INVALID && count < k)
	{
		++it;
		count++;
	}
	
	return it;
}

void VCAlgorithm::removeEdge(ListGraph::Edge e)
{
	graph->erase(e);
}

void VCAlgorithm::removeEdgesOfNode(ListGraph::Node n)
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

int VCAlgorithm::getRunTime()
{
	return runTime;
}

int VCAlgorithm::getCoverSize()
{
	return cover->size();
}

std::vector<ListGraph::Node>* VCAlgorithm::getCover()
{
	return cover;
}

