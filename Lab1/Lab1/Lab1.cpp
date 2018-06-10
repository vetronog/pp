#include "math.h" 
#include "stdafx.h" 
#include <iostream> 
#include <string> 
using namespace std;

static const size_t MIN_ARGS_COUNT = 2;
static const size_t MAX_ARGS_COUNT = 3;
static const std::string HELP_FLAG = "--h";
int main(int argc, char *argv[])
{
	if (argc > MAX_ARGS_COUNT || argc < MIN_ARGS_COUNT)
	{
		cout << "Invalid arguments count: use *.exe it_count threadCount" << endl;
		return 1;
	}
	if (argc == MIN_ARGS_COUNT && argv[1] == HELP_FLAG)
	{
		cout << "HELP MESSAGE";
		return 0;
	}

	int iterationCount = stoi(argv[1]);
	size_t threadCount = stoi(argv[2]);
	clock_t start = clock();
	//MonteCarloAlgorithm
	clock_t end = clock();
	cout << endl << "Pi number is " << endl;
	cout << endl << "Calculation Time is:" << (float)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}