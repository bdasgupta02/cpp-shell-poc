#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <stdlib.h>

// C++ CLI shell without using LLVM/JIT
// Uses G++
// Improvements: detect functions, concurrency to compensate for compilation speed
// Custom commands: refresh

#define REFRESH "refresh"
#define EXIT "exit"

// main function wrapper to execute
std::string start = "\nint main() {\n";
std::string end = "\n}";

struct History {
	std::vector<std::string> includes;
	std::string history;

	History() {
		history = "";
	}

	inline std::string join_includes() {
		return std::accumulate(includes.begin(), includes.end(), std::string(""));
	}

	void execute() {
		// if last command is assignment, then print variable
		std::ofstream out("out.cpp");
		out << join_includes() << start << history << end;
		out.close();
		system("g++ out.cpp -o out.exe");
		system("./out.exe");
	}

	int check_command(std::string str) {
		if (str == REFRESH) {
			history = "";
			includes.clear();
			execute();
			return 1;
		} else if (str == EXIT) {
			return 2;
		}
		return 0;
	}

	bool add(std::string str) {
		if (!str.size()) return true;
		
		int command = check_command(str);
		if (command == 1) return true;
		if (command == 2) return false;

		if (str[0] == '#') {
			includes.push_back(str);
			return true;
		}

		history += str + "\n";
		execute();
	}
};

bool take_input(History &hist) {
	std::cout << "\n>>> ";
	std::string inp;
	std::getline(std::cin, inp);
	return hist.add(inp);
}

int main() {
	History hist;
	bool is_running = true;
	while (is_running) is_running = take_input(hist);
	return 0;
}
