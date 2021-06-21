
#include "IPCClient.h"
#include "IPCServer.h"
#include "Application.h"

#include <string>
#include <iostream>
#include <functional>

int PromptInt(const std::string& message, std::function<bool(int value)> validatorFn)
{
	while (true)
	{
		try
		{
			std::cout << message;
			std::string input;
			std::getline(std::cin, input);
			auto result = std::stoi(input);
			if (validatorFn(result))
				return result;
			else throw "Failed Verify";
		}
		catch (...)
		{
			std::cout << "Invalid Input" << std::endl;
		}
	}
}
int main(int argc, char** argv)
{
	std::cout << "press 1 to run server" << std::endl;
	std::cout << "press 2 to run client" << std::endl;

	int prompt = PromptInt("select: ", [](int val) { 
		return val == 1 || val == 2; 
		});

	Application* app = nullptr;

	if (prompt == 1) app = new IPCServer();
	if (prompt == 2) app = new IPCClient();

	app->Run();

	delete app;

	return 0;
}