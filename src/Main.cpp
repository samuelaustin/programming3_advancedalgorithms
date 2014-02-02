#include "VCAlgorithm.h"
#include "VCGreedy.h"
#include "VCGreedyImproved.h"
#include "DimacsReader.h"
#include <sys/time.h>

using namespace lemon;
using namespace std;

int main(int argc, char** args)
{
	
	/*
	std::string file = "../files/frb59-26-mis/frb59-26-2.mis";
	*/
   	struct timeval time ;
	gettimeofday(&time, NULL);
	std::srand(time.tv_usec);
	std::string file(args[1]);
	DimacsReader* reader = new DimacsReader();
	
	ListGraph* g; 
	if(args[2][1]=='f')
		g = reader->readFile(file); 
	else
		g = reader->readString(file);
	
	if(args[2][0]=='r')
	{
		VCAlgorithm* alg = new VCAlgorithm(g);
		alg->run();
		std::cout << alg->getCoverSize() << "," << alg->getAverageRemovedEdges() << "\n";
	}
	else if(args[2][0]=='g')
	{
		VCGreedy* alg = new VCGreedy(g);
		alg->run();
		std::cout << alg->getCoverSize() << "\n";
	}
	else if(args[2][0]=='i')
	{
		VCGreedyImproved* alg = new VCGreedyImproved(g,0);		
		alg->run();		
		std::cout << alg->getCoverSize() << "\n";
	}
	else if(args[2][0]=='!')
	{
		VCGreedyImproved* alg = new VCGreedyImproved(g,1);
		alg->run();
		std::cout << alg->getCoverSize() << "\n";
	}
	else
	{
		return 1;
	}
	
	return 0;
}
