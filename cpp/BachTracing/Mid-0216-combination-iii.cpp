#include <vector>

class Solution {
	std::vector<std::vector<int>> ret;
	std::vector<int> one;
	int sum = 0;
public:
	std::vector<std::vector<int>> combinationSum3(int k, int n) {
        for (int i = 1; i <= 10 - k; i++)
	        rec(k, n, i);
		
		return ret;
	}

	void rec(int k, int n, int v)
	{
		if (sum > n) return;
		
		one.push_back(v);
		sum += v;
		if (one.size() == k)
		{
			if (sum == n)
				ret.push_back(one);
			else
			{
				one.pop_back();
				sum -= v;
				return;
			}
		}
		
		for (int i = v + 1; i < 10; i++)
			rec(k, n, i);
		
		one.pop_back();
		sum -= v;
	}
};