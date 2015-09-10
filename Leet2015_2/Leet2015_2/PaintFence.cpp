#include "stdafx.h"

//There is a fence with n posts, each post can be painted with one of the k colors.
//
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//
//Return the total number of ways you can paint the fence.
//
//Note:
//n and k are non - negative integers.

namespace Solution2
{
	namespace PaintFence
	{

		int numWays(int n, int k) {
			if (n == 0) { return 0; }
			if (n == 1) { return k; }

			int diffColorCounts = k * (k - 1);
			int sameColorCounts = k;

			for (int i = 2; i < n; i++)
			{
				int temp = diffColorCounts;
				diffColorCounts = (diffColorCounts + sameColorCounts) * (k - 1);
				sameColorCounts = temp;
			}
			return diffColorCounts + sameColorCounts;
		}



		void Main()
		{
		}
	}
}
