class Solution
{
public:
	int integerBreak(int n)
	{
		if (n == 2) return 1;
		if (n < 6) return (n - 2) * 2;
		
		int remain = n % 3, ans = 1;
		if (remain == 0)
			for (int i = 0; i < n / 3; i++)
				ans *= 3;
		else if (remain == 1)
		{
			for (int i = 0; i < n / 3 - 1; i++)
				ans *= 3;
			ans *= 4;
		}
		else
		{
			for (int i = 0; i < n / 3; i++)
				ans *= 3;
			ans *= 2;
		}
		return ans;
	}
};