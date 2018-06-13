#include "math.h" 
#include "stdafx.h" 
#include "Algorithm.h"
#include "Messenger.h"
using namespace std;


static const size_t ARGS_COUNT = 2;
static const size_t MIN_ITERATION_COUNT = 0;
static const std::string HELP_FLAG = "--h";

int main(int argc, char *argv[])
{
	if (argc != ARGS_COUNT)
	{
		Messenger::PrintErrorMessage();
		return 0;
	}
	if (argv[1] == HELP_FLAG)
	{
		Messenger::PrintHelpMessage();
		return 0;
	}
	else
	{
		try {
			size_t iterationCount = stoi(argv[1]);

			Algorithm monteCarlo(iterationCount);
			clock_t start = clock();
			monteCarlo.CalculatePointsInCircle();
			clock_t end = clock();
			cout << "Pi number is " << monteCarlo.GetPiNumber() << endl;
			cout << "Calculation Time is:" << (float)(end - start) / CLOCKS_PER_SEC << endl;
		}
		catch (...)
		{
			Messenger::PrintErrorMessage();
		}
	}
	return 0;
}