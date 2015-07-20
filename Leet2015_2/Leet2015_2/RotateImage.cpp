#include "stdafx.h"

//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees(clockwise).

namespace Solution2
{
    namespace RotateImage
    {
		void rotateOneLayer(vector<vector<int>>& matrix, int startRow, int startCol, int size)
		{
			for (int i = 0; i < size - 1; i++)
			{
				int temp = matrix[startRow][startCol + i];
				matrix[startRow][startCol + i] = matrix[startRow + size - 1 - i][startCol];
				matrix[startRow + size - 1 - i][startCol] = matrix[startRow+size-1][startCol + size - 1 - i];
				matrix[startRow + size - 1][startCol + size - 1 - i] = matrix[startRow + i][startCol + size - 1];
				matrix[startRow + i][startCol + size - 1] = temp;
			}		
		}

		void rotate(vector<vector<int>>& matrix) {
			int size = matrix.size();
			if (size < 2) { return; }

			for (int i = 0; i < size / 2; i++)
			{
				rotateOneLayer(matrix, i, i, size - 2 * i);
			}
		}
     
        void Main()
        {
			vector<vector<int>> matrix;
			matrix = { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 10 }, { 11, 12, 13, 14, 15 }, { 16, 17, 18, 19, 20 }, { 21, 22, 23, 24, 25 } };
			matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 }};
			rotate(matrix);
			print(matrix);
        }
    }
}
