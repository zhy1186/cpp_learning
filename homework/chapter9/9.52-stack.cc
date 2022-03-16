#include <stdint.h>

#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::int8_t priority(std::string inp) {
  if (inp == "(") return 1;
  if (inp == "+" || inp == "-") return 2;
  if (inp == "*" || inp == "/")
    return 3;
  else {
    std::cerr << "FATAL ERROR: unrecognized character: " << inp << std::endl;
    return -1;
  }
}

void evaluate(std::stack<int>& stk, std::string opt) {
  if (opt == "+") {
    int val1 = stk.top();
    stk.pop();
    int val2 = stk.top();
    stk.pop();
    stk.push(val1 + val2);
    return;
  }
  if (opt == "-") {
    int val1 = stk.top();
    stk.pop();
    int val2 = stk.top();
    stk.pop();
    stk.push(val2 - val1);
    return;
  }
  if (opt == "*") {
    int val1 = stk.top();
    stk.pop();
    int val2 = stk.top();
    stk.pop();
    stk.push(val1 * val2);
    return;
  }
  if (opt == "/") {
    int val1 = stk.top();
    stk.pop();
    int val2 = stk.top();
    stk.pop();
    stk.push(val2 / val1);
    return;
  }
}

std::int32_t scan_expression(std::vector<std::string> vec) {
  std::stack<std::int32_t> stk_val{};
  std::stack<std::string> stk_opt{};

  for (auto token : vec) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (stk_opt.size() == 0) {
        stk_opt.push(token);
      } else {
        std::string stk_opt_top = stk_opt.top();
        std::int8_t pri_stk_opt_top = priority(stk_opt_top);
        std::int8_t pri_token = priority(token);

        if (pri_token > pri_stk_opt_top) {
          stk_opt.push(token);
        } else {
          while (pri_token <= pri_stk_opt_top) {
            stk_opt.pop();
            evaluate(stk_val, stk_opt_top);
            if (stk_opt.size() > 0) {
              stk_opt_top = stk_opt.top();
              pri_stk_opt_top = priority(stk_opt_top);
            } else
              break;
          }
          stk_opt.push(token);
        }
      }
    }
    if (token == "(") {
      stk_opt.push(token);
    }
    if (token == ")") {
      while (stk_opt.top() != "(") {
        std::string stk_opt_top = stk_opt.top();
        evaluate(stk_val, stk_opt_top);
        stk_opt.pop();
      }
      stk_opt.pop();
    }
    if (std::isdigit(token.c_str()[0])) {
      stk_val.push(std::atoi(token.c_str()));
    }
  }

  while (stk_opt.size() != 0) {
    std::string stk_opt_top = stk_opt.top();
    evaluate(stk_val, stk_opt_top);
    stk_opt.pop();
  }

  return stk_val.top();
}

int main(int argc, char** argv) {
  std::vector<std::string> eva = {"(", "1", "+", "2", ")", "*", "3",
                                  "/", "(", "2", "-", "1", ")"};
  std::cout << scan_expression(eva) << std::endl;
  return 0;
}
