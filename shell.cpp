#include <iostream>
#include <string>
#include "evaluator.cpp"

bool take_input(Evaluator &eval)
{
	std::string inp;
	std::getline(std::cin, inp);
	return eval.add(inp);
}

void run_shell()
{
	std::string prompt = "\ncppsh> ";
	Evaluator eval;
	bool is_running = true;
	while (is_running)
	{
		std::cout << prompt;
		is_running = take_input(eval);
	}
}

int main()
{
	std::cout << "\nWelcome to the C++ Shell\n";
	run_shell();
	return 0;
}