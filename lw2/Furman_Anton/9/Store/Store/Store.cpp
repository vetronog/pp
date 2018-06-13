#include "stdafx.h"
#include "Cashier.h"
#include "Buyer.h"
#include "Mutex.h"
#include "ThreadData.h"
#include "ThreadController.h"

int main()
{
	setlocale(LC_ALL, "rus");
	ThreadController controller;
	std::vector<Cashier> cashiers;
	for (size_t i = 0; i < 3; i++)
	{
		cashiers.push_back(std::move(Cashier()));
	}
	std::vector<ThreadData> buyersData;
	for (size_t i = 0; i < 6; i++)
	{
		buyersData.emplace_back(ThreadData(cashiers, i));
	}
	for (size_t i = 0; i < buyersData.size(); i++)
	{
		controller.Add(Buyer::loop, &buyersData[i]);
	}
	controller.WaitAll();
    return 0;
}

