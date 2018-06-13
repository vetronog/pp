#pragma once
#include "stdafx.h"
class Cashier;
struct ThreadData
{
	std::vector<Cashier> &cashiers;
	int number;
	ThreadData(std::vector<Cashier> &_cashiers, int _number)
		:	cashiers(_cashiers),
			number(_number)
	{

	}
};