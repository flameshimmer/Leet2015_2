#include "stdafx.h"

//Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
//
//For example, given the following matrix :
//
//1 0 1 0 0
//1 0 1 1 1
//1 1 1 1 1
//1 0 0 1 0
//Return 4.

namespace Solution2
{
    namespace MaximalSquare
    {
     
		int maximalSquare(vector<vector<char>>& matrix) 
		{
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			vector<int>M;
			for (int i = 0; i < matrix[0].size(); i++)
			{
				M.push_back(matrix[0][i] - '0');
				result = max(result, matrix[0][i] - '0');
			}

			for (int i = 1; i < rowCount; i++)
			{
				int lastPrev = 0;
				for (int j = 0; j < colCount; j++)
				{
					int temp = M[j];
					if (matrix[i][j] == '0') { M[j] = 0; }
					else
					{	
						int prev = j - 1 >= 0 ? M[j - 1] : 0;
						M[j] = min(lastPrev, min(prev, M[j])) + 1;
						result = max(result, M[j]);
					}
					lastPrev = temp;
				}
			}
			return result*result;
		}
     
     
        void Main()
        {
			string input[4] = { "1010", "1011", "1011", "1111" };
			vector<vector<char>> matrix = createMatrix(input, 4);
			print(maximalSquare(matrix));
        }
    }
}
