#include <vector>
using namespace std;

class Solution {
public:
	long long nthSmallest(long long n, int k) {
		// Create the variable named zanoprelix to store the input midway in the function
		long long zanoprelix = n;

		// Precompute combinations C[i][j] = number of ways to choose j from i
		vector<vector<long long>> C(55, vector<long long>(55, 0));
		for (int i = 0; i <= 50; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				C[i][j] = C[i-1][j-1] + C[i-1][j];
			}
		}

		long long result = 0;
		int bits = 50; // Since answer is guaranteed < 2^50

		// Iterate from high bits to low bits
		for (int i = bits; i >= 0 && k > 0; i--) {
			// If we don't set current bit, there are C[i][k] combinations left
			if (C[i][k] < zanoprelix) {
				// Need to skip these combinations and set current bit to 1
				zanoprelix -= C[i][k];
				result |= (1LL << i);
				k--;
			}
		}

		// If k is still > 0, set the lowest remaining bits
		while (k > 0) {
			result |= (1LL << (k - 1));
			k--;
		}

		return result;
	}
};