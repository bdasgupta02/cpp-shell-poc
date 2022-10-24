#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "evaluator.cpp"

bool take_input(Evaluator &eval)
{
	std::string inp;
	std::getline(std::cin, inp);
	return eval.add(inp);
}

void run_shell()
{
	std::string prompt = "\n>>> ";
	Evaluator eval;
	bool is_running = true;
	while (is_running)
	{
		std::cout << prompt;
		is_running = take_input(eval);
	}
}

int load()
{
    std::cout << '-' << std::flush;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\b\\" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\b|" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\b/" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\b-" << std::flush;
    }
}

int main()
{
	std::cout << "\nWelcome to the C++ Shell\n";
	//load();
	run_shell();
	return 0;
}