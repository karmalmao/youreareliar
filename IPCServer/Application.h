#pragma once

class Application
{
public:
    struct MyData
    {
        int i;
        float f;
        char c;
        bool b;
        double d;
    };



    wchar_t m_sharedMemory[15] = L"SharedMem";

	Application();
	virtual ~Application();

	virtual void Run() = 0;

protected:
private:
};