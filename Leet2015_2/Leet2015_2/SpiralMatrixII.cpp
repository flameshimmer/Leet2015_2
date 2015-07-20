#include "stdafx.h"

//Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//For example,
//Given n = 3,
//
//You should return the following matrix :
//[
//	[1, 2, 3],
//	[8, 9, 4],
//	[7, 6, 5]
//]

namespace Solution2
{
    namespace SpiralMatrixII
    {
		vector<vector<int>> generateMatrix(int n) 
		{
			vector<vector<int>> matrix(n, vector<int>(n, 1));
			if (n < 2) { return matrix; }

			int upperBound = 0;
			int lowerBound = n - 1;
			int leftBound = 0;
			int rightBound = n - 1;
			int ops[4] = { 0/*right*/, 1/*down*/, 2/*left*/, 3/*up*/ };
			int curDirIndex = 0;
			int val = 1;

			while (upperBound <= lowerBound && leftBound <= rightBound)
			{
				if (ops[curDirIndex] == 0)
				{
					int row = upperBound;
					int col = leftBound;
					while (col <= rightBound)
					{
						matrix[row][col] = val;
						val++;
						col++;
					}
					upperBound++;
					curDirIndex = (curDirIndex + 1) % 4;
				}
				else if (ops[curDirIndex] == 1)
				{
					int row = upperBound;
					int col = rightBound;
					while (row <= lowerBound)
					{
						matrix[row][col] = val;
						val++;
						row++;
					}
					rightBound--;
					curDirIndex = (curDirIndex + 1) % 4;
				}
				else if (ops[curDirIndex] == 2)
				{
					int row = lowerBound;
					int col = rightBound;
					while (col >= leftBound)
					{
						matrix[row][col] = val;
						val++;
						col--;
					}
					lowerBound--;
					curDirIndex = (curDirIndex + 1) % 4;
				}
				else if (ops[curDirIndex] == 3)
				{
					int row = lowerBound;
					int col = leftBound;
					while (row >= upperBound)
					{
						matrix[row][col] = val;
						val++;
						row--;
					}
					leftBound++;
					curDirIndex = (curDirIndex + 1) % 4;
				}
			}
			return matrix;
		}
     
        void Main()
        {
			print(generateMatrix(4));
        }
    }
}
