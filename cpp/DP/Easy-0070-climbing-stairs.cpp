class Solution
{
public:
	int climbStairs(int n)
	{
		if (n == 1) return 1;
		if (n == 2) return 2;
		int prev = 1, next = 2;
		for (int i = 3; i <= n; i++)
		{
			next += prev;
			prev = next - prev;
		}
		return next;
	}
};