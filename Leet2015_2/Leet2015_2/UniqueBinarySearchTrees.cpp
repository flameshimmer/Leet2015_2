#include "stdafx.h"

//Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//For example,
//Given n = 3, there are a total of 5 unique BST's.
//
//1         3     3      2      1
// \       /     /      / \      \
//  3     2     1      1   3      2
// /     /       \                 \
//2     1         2                 3

namespace Solution2
{
	namespace UniqueBinarySearchTrees
	{

		namespace tooSlow
		{
			int numTrees(int n) {
				if (n < 2) { return 1; }
				int result = 0;
				for (int i = 0; i < n; i++)
				{
					result += numTrees(i) * numTrees(n - i - 1);
				}
				return result;
			}
		}


		int numTrees(int n) {
			vector<int>M(n+1, 0);
			M[0] = 1;
			M[1] = 1;
			for (int i = 2; i <= n; i++)
			{
				for (int j = 0; j < i; j++)
				{
					M[i] += M[j] * M[i - 1 - j];
				}
			}
			return M[n];
		}

		void Main()
		{
			print(numTrees(3));
		}
	}
}
