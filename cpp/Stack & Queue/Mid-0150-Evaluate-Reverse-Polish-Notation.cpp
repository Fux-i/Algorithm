#include <stack>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

class Solution {
public:
	int evalRPN(std::vector<std::string>& tokens) {
        for (auto token : tokens)
        {
	        if (token.size() == 1 && std::find(op_.begin(), op_.end(), token) != op_.end())
	        {
		        int b = stack_.top();
	        	stack_.pop();
	        	int a = stack_.top();
	        	stack_.pop();
	        	
	        	int res;
	        	if (token == "+")
	        		res = a + b;
	        	else if (token == "-")
	        		res = a - b;
	        	else if (token == "*")
	        		res = a * b;
	        	else
	        		res = a / b;
	        	stack_.push(res);
	        }
        	else
        	{
        		std::istringstream iss(token);
        		int value;
        		iss >> value;
        		stack_.push(value);
        	}
        }
		return stack_.top();
	}
private:
	std::stack<int> stack_;
	std::vector<std::string> op_{"+", "-", "*", "/"};
};