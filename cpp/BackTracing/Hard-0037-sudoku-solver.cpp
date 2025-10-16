#include <vector>

class Solution
{
	std::vector<char> nums{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	std::vector<std::vector<char>> retBoard;
public:
	void solveSudoku(std::vector<std::vector<char>>& board)
	{
		backTracing(board, 0, 0);
	}

	bool backTracing(std::vector<std::vector<char>>& board, int row, int col)
	{
		if (row == 9)
			return true;
		if (col == 9)
			return backTracing(board, row + 1, 0);
		if (board[row][col] != '.')
			return backTracing(board, row, col + 1);

		for (auto num : nums)
		{
			if (isValid(board, row, col, num))
			{
				board[row][col] = num;
				if (backTracing(board, row, col + 1))
					return true;
				board[row][col] = '.';
			}
		}
		return false;
	}

	bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c)
	{
		// row
		for (int i = 0; i < 9; i++)
		{
			if (i == col)
				continue;
			if (board[row][i] == c)
				return false;
		}

		// col
		for (int i = 0; i < 9; i++)
		{
			if (i == row)
				continue;
			if (board[i][col] == c)
				return false;
		}

		// 3*3 square
		for (int i = 0; i < 3; i++)
		{
			int newRow = (row / 3) * 3 + i;
			for (int j = 0; j < 3; j++)
			{
				int newIdx = (col / 3) * 3 + j;
				if (newRow == row && newIdx == col)
					continue;
				if (board[newRow][newIdx] == c)
					return false;
			}
		}

		return true;
	}
};