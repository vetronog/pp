#include "stdafx.h"
#include "Algorithm.h"
#include <cstdlib>
static const size_t PI_COEFICIENT = 4;
static const size_t EXPONENT = 2;
static const size_t CIRCLE_RADIUS = 1;
static const size_t DIAMETER = 2 * CIRCLE_RADIUS;

Algorithm::Algorithm(size_t iterCount)
	: m_iterationCount(iterCount),
	  m_pointsInCircleCount(0)
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
	#pragma omp parallel for 
	for (int i = 0; i < m_iterationCount; ++i)
	{
		x = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		y = (float)rand() / RAND_MAX * DIAMETER - CIRCLE_RADIUS;
		if (IsPointInCircle(x, y))
		{
			#pragma omp atomic
			++m_pointsInCircleCount;
		}
	}
	m_pi = PI_COEFICIENT * (double)m_pointsInCircleCount / m_iterationCount;
}


bool Algorithm::IsPointInCircle(float x, float y)
{
	return (pow(x, EXPONENT) + pow(y, EXPONENT)) <= CIRCLE_RADIUS;
}