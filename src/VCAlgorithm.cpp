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
	
	// Do algorithm
	for(int i = 0; i < 9999999; i++)
	{
		int a = 23;
	}
	
	clock_t end = clock();
	std::cout << "Algorithm Completed" << "\n";
	
	runTime = end - start;
	return runTime;
}

ListGraph::Edge VCAlgorithm::randomEdge()
{
	return graph->edgeFromId(0);
}

void VCAlgorithm::removeEdge(ListGraph::Edge e)
{
	
}

void VCAlgorithm::removeEdgesOfNode(ListGraph::Node n)
{
	
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

