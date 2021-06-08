#include "IPCServer.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <random>
#include <time.h>

IPCServer::IPCServer()
{

}
IPCServer::~IPCServer()
{
	// unmap the memory block since we're done with it
	UnmapViewOfFile(m_data);

	// close the shared file
	CloseHandle(m_fileHandle);
}
void IPCServer::Run()
{
	bool able = true;
	int ch;


	m_fileHandle = CreateFileMapping(INVALID_HANDLE_VALUE,nullptr,PAGE_READWRITE,0,sizeof(MyData), m_sharedMemory);
	m_data = (MyData*)MapViewOfFile(m_fileHandle,FILE_MAP_ALL_ACCESS,0,0,sizeof(MyData));
	while (able)
	{
		int i = rand() % 1000 + 1;
		float f = rand()%1000 + 1;
		char c = rand()%170 + 10;
		bool b = rand() % 2;
		double d = rand() % 1000 +1;

		MyData myData = { i, f, c, b, d };
		if (m_fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " <<
				GetLastError() << std::endl;
		}

		if (m_data == nullptr)
		{
			std::cout << "Could not map view of file: " <<
				GetLastError() << std::endl;

			CloseHandle(m_fileHandle);
		}

		// write to the memory block
		*m_data = myData;

		// wait for a keypress to close
		ch = _getch();
		if (ch == 27)
		{
			able = false;
			break;
		}
	}
}
