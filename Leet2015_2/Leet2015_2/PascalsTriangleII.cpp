#include "stdafx.h"
//
//Given an index k, return the kth row of the Pascal's triangle.
//
//
//[
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
//]
//For example, given k = 3,
//Return[1, 3, 3, 1].
//
//Note:
//Could you optimize your algorithm to use only O(k) extra space ?

namespace Solution2
{
    namespace PascalsTriangleII
    {
		vector<int> getRow(int rowIndex) {

			vector<int> result(rowIndex+1, 1);
			for (int i = 2; i <= rowIndex; i++)
			{
				for (int j = i-1; j >=1; j--)
				{
					result[j] += result[j - 1];
				}
			}
			return result;
		}
     
        void Main()
        {
			print(getRow(3));
        }
    }
}
