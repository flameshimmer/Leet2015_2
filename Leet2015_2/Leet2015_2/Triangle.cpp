#include "stdafx.h"

//Given a triangle, find the minimum path sum from top to bottom.Each step you may move to adjacent numbers on the row below.
//
//For example, given the following triangle
//[
//	[2],
//	[3, 4],
//	[6, 5, 7],
//	[4, 1, 8, 3]
//]
//The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//Note:
//Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//

namespace Solution2
{
    namespace Triangle
    {     
		int minimumTotal(vector<vector<int>>& tri) 
		{
			int rowCount = tri.size();
			if (rowCount == 0) { return 0; }

			vector<int> M(tri[rowCount - 1].size(), 0);
			copy(tri[rowCount - 1].begin(), tri[rowCount - 1].end(), M.begin());

			for (int j = rowCount - 2; j >= 0; j --)
			{
				for (int i = 0; i < tri[j].size(); i++)
				{
					M[i] = min(M[i], M[i + 1]) + tri[j][i];
				}
			}

			return M[0];
		}
     
        void Main()
        {
			vector<vector<int>>input = { { -1 }, { 2, 3 }, {1,  -1, -3 } };
			print(minimumTotal(input));
        }
    }
}
