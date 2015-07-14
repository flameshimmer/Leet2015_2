#include "stdafx.h"

//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
//]
namespace Solution2
{
    namespace PascalsTriangle
    {
		vector<vector<int>> generate(int numRows) 
		{
			vector<vector<int>> results;
			if (numRows == 0) { return results; }
			results.push_back(vector<int>(1, 1));

			for (int i = 2; i <= numRows; i++)
			{
				vector<int> lastRow = results[i - 2];
				vector<int> newRow(i, 1);
				for (int j = 1; j < i - 1; j++)
				{
					newRow[j] = lastRow[j - 1] + lastRow[j];
				}
				results.push_back(newRow);
			}
			return results;
		}
     
        void Main()
        {
			print(generate(5));
        }
    }
}
