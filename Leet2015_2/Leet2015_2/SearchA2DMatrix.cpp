#include "stdafx.h"

//Write an efficient algorithm that searches for a value in
//an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//For example,
//
//Consider the following matrix :
//
//[
//	[ 1,  3,  5,  7],
//	[10, 11, 16, 20],
//	[23, 30, 34, 50]
//]
//Given target = 3, return true.

namespace Solution2
{
    namespace SearchA2DMatrix
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
				else if (matrix[i][j] < target) { i++; }
				else { j--; }
			}
			return false;
		}
     
     
        void Main()
        {
         
        }
    }
}
