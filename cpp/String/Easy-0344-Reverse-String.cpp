#include <vector>

class Solution {
public:
	void reverseString(std::vector<char>& s) {
		auto size = s.size();
		for (size_t i = 0; i < size / 2; i++)
		{
			char temp = s[i];
			s[i] = s[size - 1 - i];
			s[size - 1 - i] = temp;
		}
	}
};