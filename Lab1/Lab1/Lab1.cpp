#include "math.h" 
#include "stdafx.h" 
#include <iostream> 
#include <string> 
using namespace std;

const size_t ARGS_COUNT = 3;

int main(int argc, char *argv[])
{
	if (argc != ARGS_COUNT)
	{
		cout << "Invalid arguments count: use *.exe it_count threadCount" << endl;
	}
	int iterationCount = stoi(argv[1]);
	size_t threadCount = stoi(argv[2]);

	return 0;
}