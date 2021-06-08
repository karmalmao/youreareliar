#pragma once
#include "Application.h"
#include <Windows.h>

class IPCServer : public Application
{
public:
	IPCServer();
	virtual ~IPCServer();

	virtual void Run();

    // open a named shared memory block
    HANDLE m_fileHandle;

    // map the memory from the shared block to a pointer we can manipulate
    MyData* m_data;
protected:
private:
};