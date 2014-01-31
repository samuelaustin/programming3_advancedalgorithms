#include "VCAlgorithm.h"
#include "DimacsReader.h"

using namespace lemon;

int main(int argc, char* args[])
{
	std::string file(args[1]);
	
	/*
	std::string file = "../files/frb59-26-mis/frb59-26-2.mis";
	*/
	std::srand(time(0));
	
	DimacsReader* reader = new DimacsReader();
	ListGraph* g = reader->readString(file);
	
	VCAlgorithm* alg = new VCAlgorithm(g);
	alg->run();
	
	std::cout << alg->getCoverSize() << "\n";
	
	return 0;
}
