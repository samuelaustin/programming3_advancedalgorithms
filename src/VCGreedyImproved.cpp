#include <ctime>
#include "VCGreedyImproved.h"


VCGreedyImproved::VCGreedyImproved(ListGraph* g)
{
	graph = g;
	elist = new std::vector<ListGraph::Edge>();
	nlist = new std::vector<ListGraph::Node>();
	nmap =  new ListGraph::NodeMap<int>(*graph,0);
	emap =  new ListGraph::EdgeMap<int>(*graph,0);

	for(ListGraph::EdgeIt it(*graph); it != INVALID; ++it)
		elist->push_back(it);
	for(ListGraph::NodeIt it(*graph); it != INVALID; ++it)
		nlist->push_back(it);
}

int VCGreedyImproved::run()
{
	clock_t start = clock();
	//Perform algorithm while there are still edges in the graph
	while((*emap)[GreedyEdge()] == 0)
	{
		//Choose a random edge
		ListGraph::Edge e = GreedyEdge();
		
		ListGraph::Node u = graph->u(e);
		ListGraph::Node v = graph->v(e);
		
		//Remove all edges of the added nodes
		removeEdgesOfNode(u);
		removeEdgesOfNode(v);
	}
	prune_set();
	clock_t end = clock();
	
	runTime = ((double)(end - start))/(CLOCKS_PER_SEC/1000);
	return runTime;
}

ListGraph::Edge VCGreedyImproved::GreedyEdge()
{
	std::sort(elist->begin(),elist->end(), [&](ListGraph::Edge e1,ListGraph::Edge e2)->bool
		{
			int ec1 = countIncEdges(*graph, graph->u(e1)) + countIncEdges(*graph,graph->v(e1));
			int ec2 = countIncEdges(*graph, graph->u(e2)) + countIncEdges(*graph,graph->v(e2));
			return (1-(*emap)[e1])*ec1>(1-(*emap)[e2])*ec2;
		});
	//ListGraph::EdgeIt foo(*graph);
	return *(elist->begin());
}

//bool VCGreedyImproved::sortDegree(ListGraph::Edge e1, ListGraph::Edge e2)
//{
//	return (1 - (*emap)[e1])*getDegree(e1) < (1 - (*emap)[e2])*getDegree(e2);
//}

int VCGreedyImproved::getDegree(ListGraph::Edge e)
{
	ListGraph::Node u = graph->u(e);
	ListGraph::Node v = graph->v(e);
	int sum = 0;
	for(ListGraph::OutArcIt it(*graph, u); it != INVALID; ++it)
		sum+=1-(*emap)[it];
	for(ListGraph::OutArcIt it(*graph, v); it != INVALID; ++it)
		sum+=1-(*emap)[it];
	
	return sum;
}

void VCGreedyImproved::removeEdge(ListGraph::Edge e)
{
	graph->erase(e);
}

void VCGreedyImproved::removeEdgesOfNode(ListGraph::Node n)
{
	(*nmap)[n] = 1;
	for(ListGraph::OutArcIt it(*graph, n); it != INVALID; ++it)
		(*emap)[it] = 1;	
}

int VCGreedyImproved::getRunTime()
{
	return runTime;
}

int VCGreedyImproved::getCoverSize()
{
	int sum = 0;
	for(ListGraph::NodeIt it(*graph); it != INVALID; ++it)
		sum += (*nmap)[it];
	return sum;
}

void VCGreedyImproved::prune_set()
{
	std::sort(nlist->begin(),nlist->end(), [&](ListGraph::Node n1,ListGraph::Node n2)->bool{return countIncEdges(*graph,n1)<countIncEdges(*graph,n2);});
	for(std::vector<ListGraph::Node>::iterator it = nlist->begin(); it != nlist->end(); ++it)
		if((*nmap)[*it])
		{
			bool rm = true;
			for(ListGraph::OutArcIt ite(*graph, *it); ite != INVALID; ++ite)
				if((*nmap)[graph->oppositeNode(*it,ite)]==0)
				{
					rm = false;
					break;
				}
			if(rm)
				(*nmap)[*it]=0;
		}		
}

