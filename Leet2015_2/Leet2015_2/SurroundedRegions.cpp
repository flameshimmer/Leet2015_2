#include "stdafx.h"


//Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//For example,
//		X X X X
//		X O O X
//		X X O X
//		X O X X
//After running your function, the board should be :
//
//		X X X X
//		X X X X
//		X X X X
//		X O X X

namespace Solution2
{
    namespace SurroundedRegions
    {
		void flipAndExpand(vector<vector<char>>& board, int row, int col, int rowCount, int colCount)
		{
			stack<pair<int, int>> stack;
			stack.push(make_pair(row, col));

			while (!stack.empty())
			{
				pair<int, int> cur = stack.top();
				stack.pop();
				int row = cur.first;
				int col = cur.second;
				board[row][col] = '-';

				if (row-1 >= 0 && row-1 < rowCount && board[row-1][col] == 'O')
				{
					stack.push(make_pair(row-1, col));
				}
				if (row+1 >= 0 && row+1 < rowCount && board[row+1][col] == 'O')
				{
					stack.push(make_pair(row+1, col));
				}
				if (col-1 >= 0 && col-1 < colCount && board[row][col-1] == 'O')
				{
					stack.push(make_pair(row, col-1));
				}
				if (col + 1 >= 0 && col + 1 < colCount && board[row][col + 1] == 'O')
				{
					stack.push(make_pair(row, col + 1));
				}
			}
		}
     
		void solve(vector<vector<char>>& board) 
		{
			int rowCount = board.size();
			if (rowCount == 0) { return; }
			int colCount = board[0].size();
			if (colCount == 0) { return; }

			for (int i = 0; i < colCount; i++)
			{
				if (board[0][i] == 'O') { flipAndExpand(board, 0, i, rowCount, colCount); }
				if (board[rowCount - 1][i] == 'O') { flipAndExpand(board, rowCount - 1, i, rowCount, colCount); }
			}

			for (int i = 0; i < rowCount; i++)
			{
				if (board[i][0] == 'O') { flipAndExpand(board, i, 0, rowCount, colCount); }
				if (board[i][colCount-1] == 'O') { flipAndExpand(board, i, colCount-1, rowCount, colCount); }
			}

			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					if (board[i][j] == 'O') { board[i][j] = 'X'; }
					else if (board[i][j] == '-') { board[i][j] = 'O'; }
				}
			}
		}
     
        void Main()
        {
			vector<vector<char>> board = { { 'O', 'O' }, { 'O', 'O' } };

			solve(board);
        }
    }
}
