#include "stdafx.h"

//Given a positive integer n, find the least number of perfect square numbers(for example, 1, 4, 9, 16, ...) which sum to n.
//
//For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

namespace Solution2
{
	namespace PerfectSquares
	{
		int numSquares(int n) {
			if (n == 0) { return 0; }
			vector<int> dp(n + 1, 0);

			for (int i = 0; i < n + 1; i++)
			{
				dp[i] = i;

				for (int j = 2; j <= sqrt(i); j++)
				{
					dp[i] = min(dp[i], 1 + dp[i - j*j]);
				}
			}
			return dp[n];
		}

		void Main()
		{
			print(numSquares(12));
		}
	}
}
