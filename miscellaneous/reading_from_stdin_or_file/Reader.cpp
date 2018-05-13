#include <fstream>
#include "Reader.hpp"

Reader::Reader()
{
	input_ = nullptr;
	readingFromFile = false;
}

void Reader::initStream(int argc, char** argv)
{
	if (argc == 2){
		std::ifstream* ptrToIfs = new std::ifstream(argv[1]);
		(*ptrToIfs).exceptions(std::ifstream::failbit | std::ifstream::badbit);
		input_ = static_cast<std::istream*>(ptrToIfs);
		readingFromFile = true;
	}
	else{
		input_ = &std::cin;
		readingFromFile = false;
	}
}

void Reader::printResult()
{
	std::string str;
	if (!readingFromFile)
		std::cout << "Type something: ";
	getline(*input_, str);
	std::cout << "Output of the program: " << str << std::endl;
}

Reader::~Reader()
{
	if (readingFromFile){
		(*(static_cast<std::ifstream*>(input_))).close();
		delete input_;
	}
}
