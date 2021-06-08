#pragma once

#include "Application.h"
#include <Windows.h>
class IPCClient : public Application 
{
public:
	IPCClient();
	virtual ~IPCClient();

	virtual void Run();

	HANDLE fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

	// map the memory from the shared block to a pointer we can manipulate
	MyData* data = (MyData*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(MyData));
protected:
private:
};