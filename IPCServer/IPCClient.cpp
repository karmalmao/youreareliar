#include "IPCClient.h"
#include <windows.h>
#include <iostream>
#include <conio.h>

IPCClient::IPCClient()
{

}
IPCClient::~IPCClient()
{
	// unmap the memory block since we're done with it
	UnmapViewOfFile(data);

	// close the shared file
	CloseHandle(fileHandle);
}
void IPCClient::Run()
{
	while (true)
	{
		if (fileHandle == nullptr)
		{
			std::cout << "Could not create file mapping object: " << GetLastError() << std::endl;
		}


		if (data == nullptr)
		{
			std::cout << "Could not map view of file: " << GetLastError() << std::endl;
			CloseHandle(fileHandle);
		}

		// write out what is in the memory block
		std::cout << std::boolalpha;
		std::cout << "MyData = { ";
		std::cout << data->i << ", ";
		std::cout << data->f << ", ";
		std::cout << data->c << ", ";
		std::cout << data->b << ", ";
		std::cout << data->d << ", ";
		std::cout << " };" << std::endl;

		// wait for a keypress to close
		Sleep(150);
		system("cls");
	}
}