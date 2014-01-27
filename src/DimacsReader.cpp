#include "DimacsReader.h"

using namespace lemon;

DimacsReader::DimacsReader()
{
	nodes = 0;
	edges = 0;
}

ListGraph* DimacsReader::readFile(std::string file)
{
	nodes = 0;
	edges = 0;
	
	std::cout << "Going to read DIMACS file..." << "\n";
	std::ifstream reader;
	reader.open(file);
	
	if(reader.is_open())
	{
		std::string line = "";
		std::getline(reader, line);
		if(!line.empty())
		{
			ListGraph* g = processFirstLine(line);
		}
		
		if(nodes > 0 && edges > 0)
		{
			while(std::getline(reader, line))
			{
				if(!line.empty())
				{
					readEdge(line);
				}
			}
		}
	}
	
	reader.close();
}

ListGraph* DimacsReader::processFirstLine(std::string line)
{
	ListGraph* g = new ListGraph();
	
	std::size_t found = line.find("p edge ");
	if(found != std::string::npos)
	{
		line.erase(found, 7);
		
		std::string::size_type size;
		nodes = std::stoi(line, &size);
		edges = std::stoi(line.substr(size));
		
		std::cout << "Nodes: " << nodes << "\n";
		std::cout << "Edges: " << edges << "\n";
		
		g->reserveNode(nodes);
		g->reserveEdge(edges);
		
		for(int i = 0; i < nodes; i++)
		{
			g->addNode();
		}
	}
	
	return g;
}

void DimacsReader::readEdge(std::string line)
{
	
}

int DimacsReader::numberOfNodes()
{
	return nodes;
}

int DimacsReader::numberOfEdges()
{
	return edges;
}
