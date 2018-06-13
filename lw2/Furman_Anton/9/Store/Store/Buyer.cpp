#include "stdafx.h"
#include "Buyer.h"
#include "ThreadData.h"
#include "Cashier.h"
Buyer::Buyer()
{
}


Buyer::~Buyer()
{
}

DWORD Buyer::loop(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	seed *= threadData->number;
	std::mt19937 random(seed);
	while (true)
	{ 
		int cashNumber = random() % 3;
		std::printf("���������� %d �������� ��������\n", threadData->number);
		Sleep(random() % 2000 + 2000);
		std::printf("���������� %d ���� �� ����� %d \n", threadData->number, cashNumber);
		threadData->cashiers.at(cashNumber).Lock();
		std::printf("���������� %d �������� �� ����� %d \n", threadData->number, cashNumber);
		Sleep(random() % 1000 + 1000);
		std::printf("���������� %d ������ � ����� %d \n", threadData->number, cashNumber);
		threadData->cashiers.at(cashNumber).Unlock();
	}
}