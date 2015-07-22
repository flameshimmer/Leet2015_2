#include "stdafx.h"

//Determine if a Sudoku is valid, according to : Sudoku Puzzles - The Rules.(http://sudoku.com.au/TheRules.aspx)
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//
//A partially filled sudoku which is valid.
//
//Note :
//	 A valid Sudoku board(partially filled) is not necessarily solvable.
//	 Only the filled cells need to be validated.
//

namespace Solution2
{
    namespace ValidSudoku
    {
		bool checkNineGrid(vector<vector<char>>& board, int startRow, int startCol, bool map[])
		{
			for (int i = startRow; i < startRow + 3; i++)
			{
				for (int j = startCol; j < startCol + 3; j++)
				{
					char val = board[i][j];
					if (val == '.') { continue; }
					if (map[val-'0']) { return false; }
					map[val-'0'] = true;
				}
			}
			return true;
		}

		bool isValidSudoku(vector<vector<char>>& board) 
		{
			int rowCount = board.size();
			if (rowCount == 0) { return false; }
			int colCount = board[0].size();
			if (colCount == 0) { return false; }

			// check each rows
			for (int i = 0; i < rowCount; i++)
			{
				bool map[10] = { false };
				for (char v : board[i])
				{
					if (v == '.') { continue; }
					if (map[v - '0']) { return false; }
					map[v - '0'] = true;
				}
			}
			// check each col
			for (int j = 0; j < colCount; j++)
			{
				bool map[10] = { false };
				for (int i = 0; i < rowCount; i++)
				{
					char v = board[i][j];
					if (v == '.') { continue; }
					if (map[v - '0']) { return false; }
					map[v - '0'] = true;
				}
			}

			//check nine grid
			for (int i = 0; i < rowCount; i += 3)
			{
				for (int j = 0; j < colCount; j += 3)
				{
					bool map[10] = { false };
					if (!checkNineGrid(board, i, j, map)) { return false; }
				}
			}
			return true;
		}
     
     
        void Main()
        {
			string rawInput[9] = { ".87654321", "2........", "3........", "4........", "5........", "6........", "7........", "8........", "9........" };
			vector<vector<char>> board = createMatrix(rawInput, 9);
			print(isValidSudoku(board));
        }
    }
}
