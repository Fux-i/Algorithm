#include <algorithm>
#include <string>
#include <vector>
#include <ranges>

using namespace std;

class Solution
{
public:
	int findMaxForm(vector<string>& strs, int m, int n)
	{
		vector f(m + 1, vector<int>(n + 1));
		for (string& s : strs)
		{
			int cnt0 = ranges::count(s, '0');
			int cnt1 = s.size() - cnt0;
			
			for (int j = m; j >= cnt0; j--)
				for (int k = n; k >= cnt1; k--)
					f[j][k] = max(f[j][k], f[j - cnt0][k - cnt1] + 1);


		}
		return f[m][n];
	}
};