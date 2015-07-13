#include "stdafx.h"

//Given a m x n grid filled with non - negative numbers, 
//find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.

namespace Solution2
{
    namespace MinimumPathSum
    {
		int minPathSum(vector<vector<int>>& grid) 
		{
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			vector<int> M(grid[0].begin(), grid[0].end());
			for (int i = 1; i < colCount; i++)
			{
				M[i] += M[i - 1];
			}

			for (int i = 1; i < rowCount; i++)
			{
				M[0] += grid[i][0];
				for (int j = 1; j < colCount; j++)
				{
					M[j] = min(M[j - 1], M[j]) + grid[i][j];
				}
			}
			return M[colCount - 1];
		}
     
        void Main()
        {
         
        }
    }
}
