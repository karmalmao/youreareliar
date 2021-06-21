#pragma once

#include "Application.h"
#include <Windows.h>
class IPCClient : public Application 
{
public:
	IPCClient();
	virtual ~IPCClient();

	virtual void Run();

	HANDLE m_fileHandle;

	// map the memory from the shared block to a pointer we can manipulate
	MyData* m_data;
protected:
private:
};