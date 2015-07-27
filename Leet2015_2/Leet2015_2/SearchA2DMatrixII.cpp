#include "stdafx.h"

//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.
//For example,
//
//Consider the following matrix :
//
//[
//	[1,  4,  7,  11, 15],
//	[2,  5,  8,  12, 19],
//	[3,  6,  9,  16, 22],
//	[10, 13, 14, 17, 24],
//	[18, 21, 23, 26, 30]
//]
//Given target = 5, return true.
//
//Given target = 20, return false.

namespace Solution2
{
	namespace SearchA2DMatrixII
	{

		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return false; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return false; }
			
			int i = 0;
			int j = colCount - 1;
			while (i < rowCount && j >= 0)
			{
				if (matrix[i][j] == target) { return true; }
				while (j >= 0 && matrix[i][j] > target){ j--; }
				while (i < rowCount && matrix[i][j] < target) { i++; }
			}
			return false;
		}

		void Main()
		{
			vector<vector<int>> matrix;

			matrix = {
					{ 1,   2,  3,  4,  5 },
					{ 6,   7,  8,  9, 10 },
					{ 11, 12, 13, 14, 15 },
					{ 16, 17, 18, 19, 20 },
					{ 21, 22, 23, 24, 25 }
			};
			print(searchMatrix(matrix, 5));


			matrix = {
					{ 1, 3, 5 }
			};
			print(searchMatrix(matrix, 3));

			matrix = {
					{ -5 }
			};
			print(searchMatrix(matrix, -2));

			matrix = {
					{ 1, 4, 7, 11, 15 },
					{ 2, 5, 8, 12, 19 },
					{ 3, 6, 9, 16, 22 },
					{ 10, 13, 14, 17, 24 },
					{ 18, 21, 23, 26, 30 }
			};
			print(searchMatrix(matrix, 5));
			print(searchMatrix(matrix, 20));


		}
	}
}