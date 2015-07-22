#include "stdafx.h"

//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the 
//bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?

namespace Solution2
{
    namespace UniquePaths
    {
     
		int uniquePaths(int m, int n) {
			if (m == 0 || n == 0) { return 0; }
			vector<int> M(n, 1);
			for (int i = 1; i < m; i++)
			{
				M[0] = 1;
				for (int j = 1; j < n; j++)
				{
					M[j] += M[j - 1];
				}
			}
			return M[n - 1];
		}
     
     
        void Main()
        {
			print(uniquePaths(2, 2));
        }
    }
}
