#include "stdafx.h"

//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, 
//where "adjacent" cells are those horizontally or vertically neighboring.
//The same letter cell may not be used more than once.
//
//For example,
//Given board =
//
//[
//	["ABCE"],
//	["SFCS"],
//	["ADEE"]
//]
//word = "ABCCED", ->returns true,
//word = "SEE", ->returns true,
//word = "ABCB", ->returns false.

namespace Solution2
{
    namespace WordSearch
    {
		bool searchHere(vector<vector<char>>& board, int row, int col, int rowCount, int colCount, string word, int index, int lenw, bool* used)
		{
			if (index == lenw) { return true; }
			int usedIndex = row*colCount + col;
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || used[usedIndex] || word[index] != board[row][col]) { return false; }
		
			used[usedIndex] = true;
			if (searchHere(board, row, col - 1, rowCount, colCount, word, index + 1, lenw, used)) { return true; }
			if (searchHere(board, row, col + 1, rowCount, colCount, word, index + 1, lenw, used)) { return true; }
			if (searchHere(board, row - 1, col, rowCount, colCount, word, index + 1, lenw, used)) { return true; }
			if (searchHere(board, row + 1, col, rowCount, colCount, word, index + 1, lenw, used)) { return true; }
			used[usedIndex] = false;
			return false;
		}


		bool exist(vector<vector<char>>& board, string word) {
			int rowCount = board.size();
			if (rowCount == 0) { return false; }
			int colCount = board[0].size();
			if (colCount == 0) { return false; }
			int lens = word.length();
			if (lens == 0) { return true; }
			if (lens > rowCount * colCount) { return false; }
			
			bool* used = new bool[rowCount * colCount];
			memset(used, false, sizeof(bool) * rowCount * colCount);
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					if (board[i][j] = word[0])
					{
						if (searchHere(board, i, j, rowCount, colCount, word, 0, lens, used)) { return true; }
					}
				}
			}
			delete used;
			return false;
		}
     
        void Main()
        {
			//string rawInput[9] = { "a"};
			//vector<vector<char>> board = createMatrix(rawInput, 1);
			//print(exist(board, "a"));


			string rawInput[9] = { "ABCE", "SFCS", "ADEE"};
			vector<vector<char>> board = createMatrix(rawInput, 3);
			print(exist(board, "ABCCED"));
			print(exist(board, "SEE"));
			print(exist(board, "ABCB"));
        }
    }
}
