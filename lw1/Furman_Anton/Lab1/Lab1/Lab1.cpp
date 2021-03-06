﻿#include "math.h" 
#include "stdafx.h" 
#include "Algorithm.h"
#include "Messenger.h"
using namespace std;


static const size_t MIN_ARGS_COUNT = 2;
static const size_t MAX_ARGS_COUNT = 3;
static const size_t MIN_ITERATION_COUNT = 0;
static const std::string HELP_FLAG = "--h";

int main(int argc, char *argv[])
{
	if (argc > MAX_ARGS_COUNT || argc < MIN_ARGS_COUNT)
	{
		Messenger::PrintErrorMessage();
		return 0;
	}
	if (argc == MIN_ARGS_COUNT && argv[1] == HELP_FLAG)
	{
		Messenger::PrintHelpMessage();
		return 0;
	}
	if (argc == MIN_ARGS_COUNT && argv[1] != HELP_FLAG)
	{
		Messenger::PrintErrorMessage();
		return 0;
	}
	size_t iterationCount = stoi(argv[1]);
	size_t threadCount = stoi(argv[2]);
	if (threadCount < MIN_THREAD_COUNT || threadCount > MAX_THREAD_COUNT || iterationCount < MIN_ITERATION_COUNT)
	{
		Messenger::PrintErrorMessage();
		return 1;
	}
	Algorithm monteCarlo(iterationCount, threadCount);
	clock_t start = clock();
	monteCarlo.Start();
	clock_t end = clock();
	cout << "Pi number is "  << monteCarlo.GetPiNumber() << endl;
	cout << "Calculation Time is:" << (float)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
