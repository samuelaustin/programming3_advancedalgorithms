#include <ctime>
#include "VCAlgorithm.h"

using namespace lemon;

VCAlgorithm::VCAlgorithm(ListGraph* g)
{
	graph = g;
	
	ListGraph::EdgeIt it(*graph);
	while(it!=INVALID)
	{
		edges.push_back(it);
		++it;
	}
	
	cover = new std::vector<ListGraph::Node>();
}

int VCAlgorithm::run()
{
	std::cout << "Starting Algorithm..." << "\n";
	clock_t start = clock();
	
	//Perform algorithm while there are still edges in the graph
	while(edges.size() > 0)
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
	
	runTime = end - start;
	return runTime;
}

ListGraph::Edge VCAlgorithm::randomEdge()
{
	int n = countEdges(*graph);
	n = edges.size();
	int k = std::rand() % n;
	
	ListGraph::EdgeIt it(*graph);
	int count = 0;
	while(it!=INVALID && count < k)
	{
		++it;
		count++;
	}
	
	
	return edges[k];
}

void VCAlgorithm::removeEdge(ListGraph::Edge e)
{
	for(std::vector<ListGraph::Edge>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		if(*it == e)
		{
			edges.erase(it);
			return;
		}
	}
}

void VCAlgorithm::removeEdgesOfNode(ListGraph::Node n)
{
	std::vector<ListGraph::Edge>::iterator it = edges.begin();
	while(it != edges.end())
	{
		if(graph->u(*it) == n || graph->v(*it) == n)
		{
			it = edges.erase(it);
		}
		else
		{
			++it;
		}
	}
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

