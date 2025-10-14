#include <string>
#include <vector>


/**
 * 可改进：列、左斜、右斜可以分别用一个 vector 来存储有没有 Qween，遍历行，所以行不用存
 */
class Solution
{
	std::vector<std::string> one;
	std::vector<std::vector<std::string>> ret;
public:
	std::vector<std::vector<std::string>> solveNQueens(int n)
	{
		std::vector<unsigned> matrix(n, 0);
		backTracing(n, 0, matrix);
		return ret;
	}

	void backTracing(int n, int idx, std::vector<unsigned> matrix)
	{
		if (n == idx)
		{
			ret.push_back(one);
			return;
		}

		auto line = matrix[idx];
		for (int i = 0; i < n; i++)
		{
			// 查询这一行第 i 个位置是否可以放
			if (line & 1 << i) continue;
			
			// 可以放，将正下方、左斜下方、右斜下方设为 1
			auto newMatrix = matrix;
			for (int j = idx + 1; j < n; j++)
			{
				newMatrix[j] = newMatrix[j] | 1 << i;
				
				int left = idx + i - j;
				if (left >= 0)
					newMatrix[j] = newMatrix[j] | 1 << left;

				int right = j - (idx - i);
				if (right < n)
					newMatrix[j] = newMatrix[j] | 1 << right;
			}
			one.push_back(std::string(i, '.') + "Q" + std::string(n - i - 1, '.'));
			backTracing(n, idx + 1, newMatrix);
			one.pop_back();
		}
		
	}
};