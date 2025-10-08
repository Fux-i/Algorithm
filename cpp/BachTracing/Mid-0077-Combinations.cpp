#include <vector>

class Solution {
	std::vector<std::vector<int>> ret{};
	std::vector<int> one{};
public:
	std::vector<std::vector<int>> combine(int n, int k)
	{
		rec(n, k, 1);
		return ret;
	}

	void rec(int n, int k, int v)
	{
		if (v > n - k + 1 + one.size())
			return;
		
		if (one.size() == k)	// 满足k个
		{
			ret.push_back(one);
			return;
		}
		
		one.push_back(v);
		rec(n, k, v + 1);
		one.pop_back();
		rec(n, k, v + 1);
	}
	
	/*
	std::vector<std::vector<int>> combine(int n, int k)
	{
		for (int i = 1; i <= n - k + 1 ; i++)
			rec(n, k, i);
		return ret;
	}

	void rec(int n, int k, int v)
	{
		// push
		one.push_back(v);
		
		// rec
		if (one.size() < k)
			for (int i = v + 1; i <= n - k + 1 + one.size(); i++)
				rec(n, k, i);
		else
			ret.push_back(one);
		
		// pop
		one.pop_back();
	}
	*/
	
};