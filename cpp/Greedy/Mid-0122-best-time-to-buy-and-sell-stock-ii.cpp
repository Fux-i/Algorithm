#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int sum = 0;
		int lastVal = prices[0];
		for (size_t i = 1; i < prices.size(); i++)
		{
			int val = prices[i];
			if (val == lastVal)
				continue;
			if (val > lastVal)
			{
				sum += val - lastVal;
				lastVal = val;
			}
			else // val < lastVal
				lastVal = val;

		}
		return sum;
	}
};