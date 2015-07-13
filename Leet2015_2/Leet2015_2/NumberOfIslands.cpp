#include "stdafx.h"

//Given a 2d grid map of '1's(land) and '0's(water), count the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands 
//horizontally or vertically.You may assume all four edges of the grid are all 
//surrounded by water.
//
//		Example 1:
//
//		11110
//		11010
//		11000
//		00000
//Answer : 1
//
//		 Example 2 :
//
//		 11000
//		 11000
//		 00100
//		 00011
//Answer : 3

namespace Solution2
{
    namespace NumberOfIslands
    {
		void flipOnes(vector<vector<char>>& grid, int row, int col, int rowCount, int colCount)
		{
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount) { return; }
			if (grid[row][col] == '1')
			{
				grid[row][col] = '0';
				flipOnes(grid, row, col - 1, rowCount, colCount);
				flipOnes(grid, row, col + 1, rowCount, colCount);
				flipOnes(grid, row - 1, col, rowCount, colCount);
				flipOnes(grid, row + 1, col, rowCount, colCount);
			}
		}

		int numIslands(vector<vector<char>>& grid) 
		{
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			int count = 0;
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					if (grid[i][j] == '1')
					{
						count++;
						flipOnes(grid, i, j, rowCount, colCount);
					}
				}
			}
			return count;
		}
     
        void Main()
        {
         
        }
    }
}
