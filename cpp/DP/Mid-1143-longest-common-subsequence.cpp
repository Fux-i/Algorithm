#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int m = text2.size();
		vector dp(m + 1, 0);
		for (char c1 : text1)
			for (int j = 0, pre = 0; j < m; j++)
			{
				int temp = dp[j+1];
				dp[j+1] = c1 == text2[j] ? pre + 1 : max(dp[j+1], dp[j]);
				pre = temp;
			}
		
		return dp[m];
	}
	// int longestCommonSubsequence2(string text1, string text2)
	// {
	// 	size_t n1 = text1.size();
	// 	size_t n2 = text2.size();
	// 	vector dp(n1 + 1, vector(n2 + 1, 0));
	// 	for (size_t i = 0; i < n1; i++)
	// 	{
	// 		char c1 = text1[i];
	// 		for (size_t j = 0; j < n2; j++)
	// 		{
	// 			char c2 = text2[j];
	// 			if (c1 == c2)
	// 				dp[i+1][j+1] = dp[i][j] + 1;
	// 			else
	// 				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
	// 		}
	// 	}
	// 	return dp[n1][n2];
	// }
};