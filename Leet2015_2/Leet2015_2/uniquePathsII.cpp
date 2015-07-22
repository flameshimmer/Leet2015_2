#include "stdafx.h"

//Follow up for "Unique Paths":
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//For example,
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//The total number of unique paths is 2.
//
//Note: m and n will be at most 100.

namespace Solution2
{
    namespace uniquePathsII
    {
		
		int uniquePathsWithObstacles(vector<vector<int>>& g) {
			int rowCount = g.size();
			if (rowCount == 0) { return 0; }
			int colCount = g[0].size();
			if (colCount == 0) { return 0; }

			vector<int> M(colCount, 0);
			for (int i = 0; i < colCount; i++)
			{
				if (g[0][i] == 1) { break; }
				M[i] = 1;
			}

			bool hasBlocked = g[0][0] == 1;
			for (int i = 1; i < rowCount; i++)
			{
				if (!hasBlocked && g[i][0] == 0) { M[0] = 1; }
				else { hasBlocked = true; M[0] = 0; }

				for (int j = 1; j < colCount; j++)
				{
					if (g[i][j] == 1) { M[j] = 0; }
					else { M[j] += M[j - 1]; }
				}
			}
			return M[colCount - 1];
		}
     
     
        void Main()
        {
         
        }
    }
}
