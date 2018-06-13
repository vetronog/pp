#pragma once
#include "Mutex.h";
class Cashier : public Mutex
{
public:
	Cashier();
	~Cashier();
};

