#pragma once
class Mutex
{
public:
	Mutex();
	virtual ~Mutex();
	void Lock();
	void Unlock();
private:
	HANDLE m_mutex;
};

