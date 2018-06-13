#include "stdafx.h"
#include "Messenger.h"

static const std::string ITERATION_COUNT_MESSAGE = "<iteration_count> - positive value";
static const std::string HELP_MESSAGE = "Use Lab1.exe <iteration_count> \n" + ITERATION_COUNT_MESSAGE;
static const std::string ERROR_MESSAGE = "Invalid arguments \n" "Use Lab1.exe --h for help";

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
