#include "DimacsReader.h"

using namespace lemon;

DimacsReader::DimacsReader()
{
	nodes = 0;
	edges = 0;
}

ListGraph* DimacsReader::readFile(std::string file)
{
	g.clear();
	nodes = 0;
	edges = 0;
	
	std::ifstream reader;
	reader.open(file);
	
	if(reader.is_open())
	{
		std::string line = "";
		// Skip comments
		while(reader.peek() == 'c')
		{
			std::getline(reader, line);
		}
		
		// Get first line which indicates number of nodes/edges
		std::getline(reader, line);
		if(!line.empty())
		{
			processFirstLine(line);
		}
		
		if(nodes > 0 && edges > 0)
		{
			for(int i = 0; i < edges; i++)
			{
				std::getline(reader, line);
				if(!line.empty())
				{
					readEdge(line);
				}
			}
		}
	}
	
	reader.close();
	return &g;
}

ListGraph* DimacsReader::readString(std::string s)
{
	g.clear();
	nodes = 0;
	edges = 0;
	
	std::istringstream reader(s);
	std::string line = "";
	while(reader.peek() == 'c')
	{
		std::getline(reader, line);
	}
	
	// Get first line which indicates number of nodes/edges
	std::getline(reader, line);
	if(!line.empty())
	{
		processFirstLine(line);
	}
	
	if(nodes > 0 && edges > 0)
	{
		for(int i = 0; i < edges; i++)
		{
			std::getline(reader, line);
			if(!line.empty())
			{
				readEdge(line);
			}
		}
	}
	return &g;
}

void DimacsReader::processFirstLine(std::string line)
{
	std::size_t found = line.find("p edge ");
	if(found != std::string::npos)
	{
		line.erase(found, 7);
		
		std::string::size_type size;
		nodes = std::stoi(line, &size);
		edges = std::stoi(line.substr(size));
		
		g.reserveNode(nodes);
		g.reserveEdge(edges);
		
		for(int i = 0; i < nodes; i++)
		{
			g.addNode();
		}
	}
}

void DimacsReader::readEdge(std::string line)
{
	if(line[0] == 'e')
	{
		line.erase(0,1);
		
		std::string::size_type size;
		int nodeID1 = std::stoi(line, &size);
		int nodeID2 = std::stoi(line.substr(size));
		
		ListGraph::Node n1 = g.nodeFromId(nodeID1);
		ListGraph::Node n2 = g.nodeFromId(nodeID2);
		
		if(g.valid(n1) && g.valid(n2))
		{
			g.addEdge(n1, n2);
		}
	}
}

int DimacsReader::numberOfNodes()
{
	return nodes;
}

int DimacsReader::numberOfEdges()
{
	return edges;
}
