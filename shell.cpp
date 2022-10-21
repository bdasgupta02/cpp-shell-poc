#include <iostream>
#include <string>
#include "history.cpp"

bool take_input(History &hist)
{
	std::string inp;
	std::getline(std::cin, inp);
	return hist.add(inp);
}

void run_shell()
{
	std::string prompt = "\n>>> ";
	History hist;
	bool is_running = true;
	while (is_running)
	{
		std::cout << prompt;
		is_running = take_input(hist);
	}
}

int main()
{
	std::cout << "\nWelcome to the C++ Shell" << '\n';
	run_shell();
	return 0;
}