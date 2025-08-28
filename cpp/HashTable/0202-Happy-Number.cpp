#include <unordered_set>

class Solution
{
public:
	bool isHappy(int n)
	{
		std::unordered_set<int> set{};
		while (n != 1)
		{
			// 出现循环，不是快乐数
			if (set.find(n) != set.end())
				return false;
			set.insert(n);
			
			int sum = 0;
			while (n > 0)
			{
				int a = n % 10;
				n = n / 10;
				sum += a * a;
			}

			n = sum;
		}
		return true;
	}
};