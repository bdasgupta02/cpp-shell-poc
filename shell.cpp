#include <iostream>
#include <string>
#include "history.cpp"

static const std::string prompt = "\n>>> ";

bool take_input(History &hist)
{
	std::cout << prompt;
	std::string inp;
	std::getline(std::cin, inp);
	return hist.add(inp);
}

int main()
{
	std::cout << "\nWelcome to the C++ Shell" << '\n';
	History hist;

	bool is_running = true;
	while (is_running)
		is_running = take_input(hist);

	return 0;
}
