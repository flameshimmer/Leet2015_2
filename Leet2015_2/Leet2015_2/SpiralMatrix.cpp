#include "stdafx.h"

//Given a matrix of m x n elements(m rows, n columns), 
//return all elements of the matrix in spiral order.
//
//For example,
//Given the following matrix :
//
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//You should return[1, 2, 3, 6, 9, 8, 7, 4, 5].

namespace Solution2
{
    namespace SpiralMatrix
    {     
		vector<int> spiralOrder(vector<vector<int>>& matrix) {
			vector<int> result;
			int rowCount = matrix.size();
			if (rowCount == 0) { return result; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return result; }

			int leftBound = 0;
			int rightBound = colCount - 1;
			int upperBound = 0;
			int lowerBound = rowCount - 1;

			int ops[4] = { 0/*right*/, 1/*down*/, 2/*left*/, 3/*up*/ };
			int row = 0;
			int col = 0;
			int curDirIndex = 0;
			while (leftBound <= rightBound && upperBound <= lowerBound)
			{
				if (ops[curDirIndex] == 0)
				{
					row = upperBound;
					col = leftBound;
					while (col <= rightBound)
					{
						result.push_back(matrix[row][col]);
						col++;
					}
					curDirIndex = (curDirIndex + 1) % 4;
					upperBound++;
				}
				else if (ops[curDirIndex] == 1)
				{
					col = rightBound;
					row = upperBound;
					while (row <= lowerBound)
					{
						result.push_back(matrix[row][col]);
						row++;
					}
					curDirIndex = (curDirIndex + 1) % 4;
					rightBound--;
				}
				else if (ops[curDirIndex] == 2)
				{
					row = lowerBound;
					col = rightBound;
					while (col >= leftBound)
					{
						result.push_back(matrix[row][col]);
						col--;
					}
					curDirIndex = (curDirIndex + 1) % 4;
					lowerBound--;
				}
				else if (ops[curDirIndex] == 3)
				{
					col = leftBound;
					row = lowerBound;
					while (row >= upperBound)
					{
						result.push_back(matrix[row][col]);
						row--;
					}
					curDirIndex = (curDirIndex + 1) % 4;
					leftBound++;
				}
			}
			return result;
		}

        void Main()
        {
			vector<vector<int>> matrix;
			matrix = { { 3 }, { 2 } };		
			print(spiralOrder(matrix));
			
			matrix = { { 3, 2 } };
			print(spiralOrder(matrix));
        }
    }
}
