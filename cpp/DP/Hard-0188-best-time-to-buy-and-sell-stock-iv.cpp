#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxProfit(int k, vector<int>& prices)
	{
		vector<array<int, 2>> f(k + 2, {INT_MIN / 2, INT_MIN / 2});
		for (int j = 1; j <= k + 1; j++)
			f[j][0] = 0;
		
		for (int p : prices)
			for (int j = k + 1; j > 0; j--)
			{
				f[j][0] = max(f[j][0], f[j][1] + p);
				f[j][1] = max(f[j][1], f[j - 1][0] - p);
			}
		return f[k + 1][0];
	}
};