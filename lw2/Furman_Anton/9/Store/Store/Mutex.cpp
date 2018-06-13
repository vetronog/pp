#include "stdafx.h"
#include "Mutex.h"


Mutex::Mutex()
	:
	m_mutex(CreateMutex(NULL, FALSE, NULL))
{
	
}


Mutex::~Mutex()
{
}

void Mutex::Lock()
{
	WaitForSingleObject(m_mutex, INFINITE);
}

void Mutex::Unlock()
{
	ReleaseMutex(m_mutex);
}
