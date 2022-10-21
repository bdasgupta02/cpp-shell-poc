#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <stack>
#include <stdlib.h>

// C++ CLI shell without using LLVM/JIT
// Uses G++
// Improvements: detect functions (with func caching), concurrency to compensate for compilation speed
// Custom commands: refresh, undo, exit

#define REFRESH "refresh"
#define EXIT "exit"
#define UNDO "undo"
#define INC_ENTRY 'i'
#define MAIN_ENTRY 'm'

// main function wrapper to execute
const std::string main_start = "\nint main() {\n";
const std::string main_end = "\n}\n";

struct History {
	std::vector<std::string> pre_lines;
	std::vector<std::string> main_func;
	std::stack<char> instructions;

	inline std::string join_main() {
		return std::accumulate(main_func.begin(), main_func.end(), std::string(""));
	}

	inline std::string join_pre() {
		return std::accumulate(pre_lines.begin(), pre_lines.end(), std::string(""));
	}

	inline std::string semi_check(std::string str) {
		return str[str.size() - 1] == ';' ? str : str + ';';
	}

	void execute() {
		std::ofstream out("shell_out.cpp");
		out << join_pre() << main_start << join_main() << main_end;
		out.close();
		system("g++ shell_out.cpp -o shell_out.out && ./shell_out.out");
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

			char instr = instructions.top();	
			instructions.pop();
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

		if (str[0] == '#') {
			pre_lines.push_back(str + '\n');
			instructions.push(INC_ENTRY);
			execute();
			return true;
		}

		std::string pre_processed = semi_check(str) + '\n';

		if (str.size() > 4 && str.substr(0, 5) == "using") {
			pre_lines.push_back(pre_processed);
			instructions.push(INC_ENTRY);
			execute();
			return true;
		}
		
		main_func.push_back(pre_processed);
		instructions.push(MAIN_ENTRY);
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
	std::cout << "\nWelcome to the C++ Shell" << '\n';
	History hist;
	bool is_running = true;
	while (is_running) is_running = take_input(hist);
	return 0;
}
