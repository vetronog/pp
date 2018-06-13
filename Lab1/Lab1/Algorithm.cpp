#include "stdafx.h"
#include "Algorithm.h"
#include "ThreadController.h"
#include <cstdlib>
static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;
static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;

size_t Algorithm::m_pointsInCircleCount = 0;

Algorithm::Algorithm(size_t iterCount, size_t thrCount)
	: m_iterationCount(iterCount)
	, m_threadCount(thrCount)
{	std::srand(time(0));
}

double Algorithm::GetPiNumber() const
{
	return m_pi;
}

void Algorithm::Start()
{
	if (m_threadCount == 1)
	{
		SingleThreadAlgorithm();
	}
	else
	{
		MultiThreadAlgorithm();
	}
}

void Algorithm::SingleThreadAlgorithm()
{
	
	float x;
	float y;
	for (size_t i = 0; i < m_iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			++m_pointsInCircleCount;
		}
	}

	 m_pi = PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationCount;
}

DWORD Algorithm::CalculatePointsInCircle(LPVOID data)
{
	float x;
	float y;
	size_t* iterationCount = static_cast<size_t*>(data);
	for (size_t i = 0; i < *iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			InterlockedIncrement(&m_pointsInCircleCount);
		}
	}
	std::printf("%d\n", m_pointsInCircleCount);
	return 0;
}

void Algorithm::MultiThreadAlgorithm()
{
	ThreadController controller;
	std::vector<size_t> iterationThreadCount;
	size_t iterCount = m_iterationCount / m_threadCount;
	size_t iterRest = m_iterationCount % m_threadCount;

	for (size_t i = 0; i < m_threadCount; i++)
	{
		iterationThreadCount.emplace_back(iterCount);
	}
	for (size_t i = 0; i < iterRest; ++i)
	{
		++iterationThreadCount.at(i);
	}
	for (size_t i = 0; i < m_threadCount; ++i)
	{
		controller.Add(&CalculatePointsInCircle, &iterationThreadCount[i]);
	}
	controller.WaitAll();
	std::printf("%d\n", m_pointsInCircleCount);

	std::printf("%d\n", m_iterationCount);
	m_pi = PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationCount;
}
bool Algorithm::IsPointInCircle(float x, float y)
{
	return (pow(x, EXPONENT) + pow(y, EXPONENT)) <= CIRCLE_RADIUS;
}