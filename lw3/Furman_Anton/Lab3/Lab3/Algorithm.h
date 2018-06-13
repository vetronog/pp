#pragma once
class Algorithm
{
public:
	Algorithm(size_t iterCount);
	~Algorithm() = default;
	double GetPiNumber() const;
	void CalculatePointsInCircle();
private:
	static bool IsPointInCircle(float x, float y);
	double m_pi;
	static size_t m_pointsInCircleCount;
	size_t m_iterationCount; 
};

