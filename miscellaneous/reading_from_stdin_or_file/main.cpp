#include "Reader.hpp"
#include <fstream>

int main(int argc, char** argv)
{
	Reader reader;

	try{
		reader.initStream(argc, argv);
		reader.printResult();

	}
	catch (std::ifstream::failure& e){
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
