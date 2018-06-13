#include "stdafx.h"
#include "Algorithm.h"
#include <cstdlib>
static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;
static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;

size_t Algorithm::m_pointsInCircleCount = 0;

Algorithm::Algorithm(size_t iterCount)
	: m_iterationCount(iterCount)
{	std::srand(time(0));
}

double Algorithm::GetPiNumber() const
{
	return m_pi;
}


void Algorithm::CalculatePointsInCircle()
{
	float x;
	float y;
	for (size_t i = 0; i < m_iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			InterlockedIncrement(&m_pointsInCircleCount);
		}
	}
}


bool Algorithm::IsPointInCircle(float x, float y)
{
	return (pow(x, EXPONENT) + pow(y, EXPONENT)) <= CIRCLE_RADIUS;
}