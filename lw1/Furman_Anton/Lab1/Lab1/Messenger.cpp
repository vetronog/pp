#include "stdafx.h"
#include "Messenger.h"

static const std::string ITERATION_COUNT_MESSAGE = "<iteration_count> - positive value\n";
static const std::string THREAD_COUNT_MESSAGE = "<thread_count> - value in range:" + std::to_string(MIN_THREAD_COUNT) + " - " + std::to_string(MAX_THREAD_COUNT) + ")";
static const std::string ARGUMENT_MESSAGE = ITERATION_COUNT_MESSAGE + THREAD_COUNT_MESSAGE + "\n";
static const std::string HELP_MESSAGE = "Use Lab1.exe <iteration_count> <thread_count>" + ARGUMENT_MESSAGE + "/n";
static const std::string ERROR_MESSAGE = "Invalid arguments \n" "Use Lab1.exe --h for help\n";

Messenger::Messenger()
{
}

void Messenger::PrintHelpMessage()
{
	std::cout << HELP_MESSAGE << std::endl;
}

void Messenger::PrintErrorMessage()
{
	std::cout << ERROR_MESSAGE << std::endl;
}
