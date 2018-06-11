#include "stdafx.h"
#include "Algorithm.h"
#include <cstdlib>
static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;
static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;

size_t Algorithm::m_pointsInCircleCount = 0;

Algorithm::Algorithm(size_t iterCount, size_t thrCount)
	: m_iterationsCount(iterCount)
	, m_threadCount(thrCount)
{
}

double Algorithm::GetPiNumber() const
{
	return m_pi;
}

void Algorithm::Start()
{
	std::srand(time(0));
	float x;
	float y;
	for (size_t i = 0; i < m_iterationsCount; ++i)
	{
		x = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		y = float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		if (IsPointInCircle(x,y))
		{
			++m_pointsInCircleCount;
		}
	}

	m_pi = PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationsCount;
}

bool Algorithm::IsPointInCircle(float x, float y)
{
	return (pow(x, EXPONENT) + pow(y, EXPONENT)) <= CIRCLE_RADIUS;
}