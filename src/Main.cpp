#include "VCAlgorithm.h"
#include "DimacsReader.h"

using namespace lemon;

int main()
{
	std::string file = "../files/frb30-15-mis/frb30-15-2.mis";
	
	std::srand(time(0));
	
	DimacsReader* reader = new DimacsReader();
	ListGraph* g = reader->readFile(file);
	std::cout << "File read and graph created." << "\n";
	
	VCAlgorithm* alg = new VCAlgorithm(g);
	alg->run();
	
	std::cout << "Size of cover: " << alg->getCoverSize() << "\n";
	std::cout << "Run Time: " << alg->getRunTime() << "\n";
	
	return 0;
}
