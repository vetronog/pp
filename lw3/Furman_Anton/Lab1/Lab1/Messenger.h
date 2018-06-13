#pragma once
class Messenger
{
public:
	Messenger();
	~Messenger() = default;
	static void PrintHelpMessage();
	static void PrintErrorMessage();
};

