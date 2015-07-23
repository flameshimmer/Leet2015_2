#include "stdafx.h"


//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//Empty cells are indicated by the character '.'.
//
//You may assume that there will be only one unique solution.

namespace Solution2
{
	namespace SudokuSolver
	{
		bool row[9][10];
		bool col[9][10];
		bool grid[3][3][10];

		bool solve(vector<vector<char>>& board, int i, int j)
		{

			if (i >= 9) { return true; }
			int nextRow = i + (j + 1) / 9;
			int nextCol = (j + 1) % 9;
			if (board[i][j] != '.') { return solve(board, nextRow, nextCol); }

			for (int k = 1; k <= 9; k++)
			{
				if (!row[i][k] && !col[j][k] && !grid[i / 3][j / 3][k])
				{
					board[i][j] = k + '0';
					row[i][k] = true; col[j][k] = true; grid[i / 3][j / 3][k] = true;
					if (solve(board, nextRow, nextCol)) { return true; }
					board[i][j] = '.';
					row[i][k] = false; col[j][k] = false; grid[i / 3][j / 3][k] = false;
				}
			}
			return false;
		}

		void solveSudoku(vector<vector<char>>& board) {
			memset(row, 0, sizeof(row));
			memset(col, 0, sizeof(col));
			memset(grid, 0, sizeof(grid));

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (board[i][j] != '.')
					{
						int v = board[i][j] - '0';
						row[i][v] = true;
						col[j][v] = true;
						grid[i / 3][j / 3][v] = true;
					}
				}
			}
			solve(board, 0, 0);
		}


		namespace other
		{
			bool isValid(vector<vector<char>>& board, int row, int col, char val)
			{
				// check the row
				for (unsigned int i = 0; i < board[row].size(); i++)
				{
					if (board[row][i] == val)
					{
						return false;
					}
				}
				// check the col
				for (unsigned int i = 0; i < board.size(); i++)
				{
					if (board[i][col] == val)
					{
						return false;
					}
				}
				// check the nine grid
				int startRow = row / 3 * 3;
				int startCol = col / 3 * 3;
				for (int i = startRow; i < startRow + 3; i++)
				{
					for (int j = startCol; j < startCol + 3; j++)
					{
						if (board[i][j] == val)
						{
							return false;
						}
					}
				}
				return true;
			}

			bool solve(vector<vector<char>>& board, int rowCount, int colCount, int row, int col)
			{
				if (row == rowCount) { return true; }
				int nextRow = row;
				int nextCol = col + 1;
				if (nextCol == colCount)
				{
					nextCol = 0;
					nextRow++;
				}

				if (board[row][col] != '.') { return solve(board, rowCount, colCount, nextRow, nextCol); }

				for (int k = 1; k <= 9; k++)
				{
					if (!isValid(board, row, col, '0' + k)) { continue; }
					board[row][col] = k + '0';
					if (solve(board, rowCount, colCount, nextRow, nextCol)) { return true; }
				}
				board[row][col] = '.';
				return false;
			}


			void solveSudoku(vector<vector<char>>& board) {
				int rowCount = board.size();
				if (rowCount == 0) { return; }
				int colCount = board[0].size();
				if (colCount == 0) { return; }
				solve(board, rowCount, colCount, 0, 0);
			}

		}
    
        void Main()
        {
			string rawInput[9] = { "..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.." };
			vector<vector<char>> board = createMatrix(rawInput, 9);
			solveSudoku(board);
			print(board);
        }
    }
}
