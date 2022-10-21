#ifndef ShellHistory_H
#define ShellHistory_H
#include <vector>
#include <stack>
#include <string>

struct History
{
  std::vector<std::string> pre_lines;
  std::vector<std::string> main_func;
  std::stack<char> instructions;

  inline std::string join_main();
  inline std::string join_pre();
  inline std::string semi_check(std::string str);

  void execute();
  int check_command(std::string str);
  bool add(std::string str);
};

#endif