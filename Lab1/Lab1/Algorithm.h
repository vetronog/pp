#pragma once
class Algorithm
{
public:
	Algorithm(size_t iterCount, size_t thrCount);
	~Algorithm() = default;
	void Start();
	double GetPiNumber() const;
private:
	static bool IsPointInCircle(float x, float y);
	double m_pi;
	static size_t m_pointsInCircleCount;
	size_t m_iterationsCount; 
	size_t m_threadCount;
};

