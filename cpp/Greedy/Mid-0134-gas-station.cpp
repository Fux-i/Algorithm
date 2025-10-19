#include <vector>

class Solution
{
public:
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
	{
		int n = gas.size();
		int start = 0;
		while (start < n) {
			int sumOfGas = 0, sumOfCost = 0;
			int order = 0;
			while (order < n) {
				int index = (start + order) % n;
				sumOfGas += gas[index];
				sumOfCost += cost[index];
				if (sumOfCost > sumOfGas) 
					break;
				order++;
			}
			if (order == n) 
				return start;
			 
			start = start + order + 1;
			
		}
		return -1;
	}
	
	/*
	{
		int n = gas.size();
		
		for (int start = 0; start < n; start++)
		{
			int total = 0;
			for (int order = 0; order < n; order++)
			{
				int index = (start + order) % n;
				total += gas[index];
				total -= cost[index];
				if (total < 0) break;
				if (order == n - 1) return start;
			}
		}
		return -1;
	}
	*/
	
};