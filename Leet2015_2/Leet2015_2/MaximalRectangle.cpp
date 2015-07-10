#include "stdafx.h"

//Given a 2D binary matrix filled with 0's and 1's, 
//find the largest rectangle containing all ones and return its area.

namespace Solution2
{
    namespace MaximalRectangle
    {
		int findMax(vector<int>& input)
		{
			int result = -1;
			stack<int> stack;
			int len = input.size();
			for (int i = 0; i < len; i++)
			{
				if (stack.empty() || input[stack.top()] <= input[i])
				{
					stack.push(i);
				}
				else
				{
					int top = stack.top();
					stack.pop();
					int startIndex = stack.empty() ? -1 : stack.top();
					result = max(result, input[top] * (i - startIndex - 1));
					i--;
				}
			}
			return result;
		}
     
		int maximalRectangle(vector<vector<char>>& matrix) 
		{
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			vector<int> input(colCount + 1, 0);
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					if (matrix[i][j] == '0') { input[j] = 0; }
					else
					{
						input[j] += 1;
					}
				}
				result = max(result, findMax(input));
			}
			return result;
		}
     
        void Main()
        {
			string rawInput[1] = { "11" };
			vector<vector<char>> matrix = createMatrix(rawInput, 1);
			print(maximalRectangle(matrix));
        }
    }
}
