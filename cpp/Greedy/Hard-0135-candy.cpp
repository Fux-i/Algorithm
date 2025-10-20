#include <vector>

class Solution
{
public:
	int candy(std::vector<int>& ratings)
	{
		int n = ratings.size();
		std::vector<int> left(n);
		for (int i = 0; i < n; i++)
		{
			if (i > 0 && ratings[i] > ratings[i - 1])
				left[i] = left[i - 1] + 1;
			else
				left[i] = 1;
		}
		int right = 0, ret = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (i < n - 1 && ratings[i] > ratings[i + 1])
				right++;
			else
				right = 1;
			ret += std::max(left[i], right);
		}
		return ret;
	}

};

/*
{
	size_t n = ratings.size();
	std::vector<int> candies(n, 1);
	int sum = 1;
	for (size_t i = 1; i < n; i++)
	{
		if (ratings[i] > ratings[i-1])
		{
			candies[i] = candies[i-1] + 1;
			sum += candies[i];
			continue;
		}
		if (ratings[i] == ratings[i-1])
		{
			sum++;
			continue;
		}

		sum++;	// candies[i] = 1
		size_t j = i;
		while (true)
		{
			if (ratings[j-1] > ratings[j])
			{
				if (candies[j-1] > candies[j])
					break;

				candies[j-1]++;
				sum++;
			}
			else break;
			j--;
			if (j == 0) break;
		}
	}

	return sum;
}
*/