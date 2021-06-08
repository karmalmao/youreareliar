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
	UnmapViewOfFile(data);

	// close the shared file
	CloseHandle(fileHandle);
}
void IPCServer::Run()
{
	bool able = true;
	int ch;



	while (able)
	{
		int i = rand() % 1000 + 1;
		float f = rand()%1000 + 1;
		char c = rand()%170 + 10;
		bool b = rand() % 2;
		double d = rand() % 1000 +1;

		MyData myData = { i, f, c, b, d };
		if (fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " <<
				GetLastError() << std::endl;
		}

		if (data == nullptr)
		{
			std::cout << "Could not map view of file: " <<
				GetLastError() << std::endl;

			CloseHandle(fileHandle);
		}

		// write to the memory block
		*data = myData;

		// wait for a keypress to close
		ch = _getch();
		if (ch == 27)
		{
			able = false;
			break;
		}
	}
}
