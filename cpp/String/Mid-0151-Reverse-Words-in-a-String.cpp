#include <string>

class Solution
{
public:
	void trim(std::string& s)
	{
		int slow = 0, fast = 0, size = s.size();
		while (fast < size)
		{
			// 跳过连续空格
			while (fast < size && s[fast] == ' ')
				fast++;
			// 到末尾结束
			if (fast == size)
				break;
			// 单词前空格，除了第一个
			if (slow != 0)
			{
				s[slow] = ' ';
				slow++;
			}
			// 复制单词
			while (fast < size && s[fast] != ' ')
			{
				s[slow++] = s[fast++];
			}
		}
		s.resize(slow);	// 截断
	}

	void reverse(std::string& s, int begin, int end)
	{
		for (;begin < end; begin++, end--)
		{
			char temp = s[begin];
			s[begin] = s[end];
			s[end] = temp;
		}
	}

	std::string reverseWords(std::string s)
	{
		trim(s);
		int begin = 0, end = 0, size = s.size();
		reverse(s, 0, size - 1);
		while (true)
		{
			begin = end;
			while (end != size && s[end] != ' ')
				end++;
			reverse(s, begin, end - 1);
			if (end == size)
				break;
			end++;
		}

		return s;
	}
};