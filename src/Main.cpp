#include "VCAlgorithm.h"
#include "VCGreedy.h"
#include "DimacsReader.h"

using namespace lemon;

int main(int argc, char** args)
{
	std::string file(args[1]);
	
	/*
	std::string file = "../files/frb59-26-mis/frb59-26-2.mis";
	*/
	std::srand(time(0));
	
	DimacsReader* reader = new DimacsReader();
	ListGraph* g = reader->readString(file);
	if(args[2][0]=='r')
	{
		VCAlgorithm* alg = new VCAlgorithm(g);
		alg->run();
		std::cout << alg->getCoverSize() << "\n";
	}
	else if(args[2][0]=='g')
	{
		VCGreedy* alg = new VCGreedy(g);
		alg->run();
		std::cout << alg->getCoverSize() << "\n";
	}
	else
	{
		return 1;
	}
	
	return 0;
}
