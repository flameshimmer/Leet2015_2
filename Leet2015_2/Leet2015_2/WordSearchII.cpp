#include "stdafx.h"

//Given a 2D board and a list of words from the dictionary, find all words in the board.
//
//Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
//cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once in a word.
//
//For example,
//Given words = ["oath", "pea", "eat", "rain"] and board =
//
//[
//	['o', 'a', 'a', 'n'],
//	['e', 't', 'a', 'e'],
//	['i', 'h', 'k', 'r'],
//	['i', 'f', 'l', 'v']
//]
//Return["eat", "oath"].
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

namespace Solution2
{
    namespace WordSearchII
    {
		class Dict
		{
			struct Node
			{
				Node* children[26];
				bool isEnd;
				Node()
				{
					isEnd = false;
					memset(children, NULL, sizeof(children));
				}
			};
		public:
			Node* root;
			Dict()
			{
				root = new Node();
			}

			void add(string& word)
			{
				Node* cur = root;
				for (char c : word)
				{
					if (cur->children[c - 'a'] == NULL)
					{
						cur->children[c - 'a'] = new Node();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			int has(string& word)
			{
				Node* cur = root;
				for (char c : word)
				{
					if (cur->children[c - 'a'] == NULL) { return 0; }
					cur = cur->children[c - 'a'];
				}
				int result = cur->isEnd ? 2 : 1;
				if (result == 2) 
				{ 
					cur->isEnd = false; 
				}
				return result;
			}

		};

		void findHere(vector<vector<char>>& board, int row, int col, int rowCount, int colCount, Dict* dict, string& result, vector<string>& results)
		{
			if (row < 0 || row >= rowCount || col < 0 || col >= colCount || board[row][col] == '-') { return; }
			char c = board[row][col];
			board[row][col] = '-';
			result.push_back(c);

			int v = dict->has(result);
			if (v == 0)
			{
				board[row][col] = c;
				result.pop_back();
				return;
			}
			else if (v == 2)
			{
				results.push_back(result);
			}

			findHere(board, row-1, col, rowCount, colCount, dict, result, results);
			findHere(board, row+1, col, rowCount, colCount, dict, result, results);
			findHere(board, row, col-1, rowCount, colCount, dict, result, results);
			findHere(board, row, col+1, rowCount, colCount, dict, result, results);

			board[row][col] = c;
			result.pop_back();
		}

		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> results;
			int rowCount = board.size();
			if (rowCount == 0) { return results; }
			int colCount = board[0].size();
			if (colCount == 0) { return results; }
			int len = words.size();			
			Dict* dict = new Dict();
			for (string word : words) { dict->add(word); }
			string result;
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					findHere(board, i, j, rowCount, colCount, dict, result, results);
				}
			}
			return results;
		}

        void Main()
        {
			string rawInput[1] = { "ab" };
			vector<vector<char>> board = createMatrix(rawInput, 1);
			vector<string> words = { "ba" };
			print(findWords(board, words));

			//string rawInput[1] = { "aa"};
			//vector<vector<char>> board = createMatrix(rawInput, 1);
			//vector<string> words = { "aa" };
			//print(findWords(board, words));


			//string rawInput[2] = { "ab", "cd"};
			//vector<vector<char>> board = createMatrix(rawInput, 2);
			//vector<string> words = { "acdb" };
			//print(findWords(board, words));
        }
    }
}
