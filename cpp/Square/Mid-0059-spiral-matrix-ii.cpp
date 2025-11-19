#include <vector>

class Solution
{
public:
	std::vector<std::vector<int>> generateMatrix(int n)
	{
		std::vector<std::vector<int>> res(n, std::vector<int>(n));
		int i = -1, j = -1, count = n, num = 0;
		while (true)
		{
			if (count == 0)
			{
				break;
			}
			
			i++;
			j++;
			
			if (count == 1)
			{
				res[i][j] = ++num;
				break;
			}
			
			for (int k = 0; k < count - 1; k++)
			{
				res[i][j++] = ++num;
			}
			for (int k = 0; k < count - 1; k++)
			{
				res[i++][j] = ++num;
			}
			for (int k = 0; k < count - 1; k++)
			{
				res[i][j--] = ++num;
			}
			for (int k = 0; k < count - 1; k++)
			{
				res[i--][j] = ++num;
			}

			count -= 2;
		}
		return res;
	}
};