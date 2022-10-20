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
#define UNDO "undo"
#define INC_ENTRY 'i'
#define MAIN_ENTRY 'm'

// main function wrapper to execute
std::string start = "\nint main() {\n";
std::string end = "\n}";

struct History {
	std::vector<std::string> pre_lines;
	std::vector<std::string> main_func;
	std::vector<char> instructions;

	inline std::string join_main() {
		return std::accumulate(main_func.begin(), main_func.end(), std::string(""));
	}

	inline std::string join_pre() {
		return std::accumulate(pre_lines.begin(), pre_lines.end(), std::string(""));
	}

	void execute() {
		// if last command is assignment, then print variable
		std::ofstream out("out.cpp");
		out << join_pre() << start << join_main() << end;
		out.close();
		system("g++ out.cpp -o out.exe");
		system("./out.exe");
	}

	int check_command(std::string str) {
		if (str == REFRESH) {
			main_func.clear();
			pre_lines.clear();
			execute();
			return 1;
		} else if (str == EXIT) {
			return 2;
		} else if (str == UNDO) {
			if (instructions.empty()) {
				std::cout << "Nothing to undo" << std::endl;
				return 1; 
			}

			char instr = instructions.back();	
			instructions.pop_back();
			if (instr == INC_ENTRY) {
				pre_lines.pop_back();
				execute();
			} else if (instr == MAIN_ENTRY) {
				main_func.pop_back();
				execute();
			}

			return 1;
		}
		return 0;
	}

	bool add(std::string str) {
		if (str.empty()) return true;
		
		int command = check_command(str);
		if (command == 1) return true;
		if (command == 2) return false;

		std::string with_break = str + '\n';

		if (str[0] == '#') {
			pre_lines.push_back(with_break);
			instructions.push_back(INC_ENTRY);
			return true;
		}

		main_func.push_back(with_break);
		instructions.push_back(MAIN_ENTRY);
		execute();
		return true;
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
