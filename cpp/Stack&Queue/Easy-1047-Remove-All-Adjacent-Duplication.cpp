#include <vector>
#include <string>

class Solution {
public:
	std::string removeDuplicates(std::string s)
	{
		for (char c : s)
		{
			if (!v_.empty() && v_.back() == c)
				v_.pop_back();
			else
				v_.push_back(c);
		}

		for (int i = 0; i < v_.size(); i++)
			s[i] = v_[i];

		s.resize(v_.size());
		return s;
	}
private:
	std::vector<char> v_;
};