#include <iostream>

class Reader
{
	public:

		Reader();
		void initStream(int argc, char** argv);
		void printResult();
		~Reader();

	private:

		std::istream* input_;
		bool readingFromFile;
};
