#include <array>
#include <stack>
#include <string>

class Solution
{
public:
	bool isValid(std::string s)
	{
		for (char c : s)
		{
			if (std::find(l_.begin(), l_.end(), c) != l_.end())
				s_.push(c);
			else
			{
				if (s_.empty())
					return false;
				switch (s_.top())
				{
				case '(':
					if (c != ')')
						return false;
					break;
				case '[':
					if (c != ']')
						return false;
					break;
				default:
					if (c != '}')
						return false;
				}
				s_.pop();
			}
		}
		return s_.empty();
	}
private:
	std::stack<char> s_;
	std::array<char, 3> l_{'(', '[', '{'};
};