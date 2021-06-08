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
    HANDLE fileHandle = CreateFileMapping(
        INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
        nullptr, // optional security attributes
        PAGE_READWRITE, // read/write access control
        0,
        sizeof(MyData), // size of the memory block, 
        L"MySharedMemory");

    // map the memory from the shared block to a pointer we can manipulate
    MyData* data = (MyData*)MapViewOfFile(fileHandle,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        sizeof(MyData));
protected:
private:
};