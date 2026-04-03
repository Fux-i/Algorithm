#include <bitset>
#include <numeric>
#include <vector>

class Solution
{
public:
	int lastStoneWeightII(std::vector<int>& stones)
	{
		const int sum = std::accumulate(stones.begin(), stones.end(), 0);
		const int halfSum = sum / 2;
		
		std::bitset<1501> set;
		set[0] = true;
		for (const auto stone : stones)
			set |= set << stone;

		int i = halfSum;
		while (!set[i])
			i--;

        return sum - 2 * i;
	}
};