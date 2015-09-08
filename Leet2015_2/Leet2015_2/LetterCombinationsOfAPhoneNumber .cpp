#include "stdafx.h"

//Given a digit string, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.
//
//2-> a, b, c
//3-> d, e, f
//4-> g, h, i
//5 -> j, k, l
//6 -> m, n, o
//7-> p, q, r, s
//8-> t, u, v
//9-> w, x, y, z
//
//Input:Digit string "23"
//  Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//	   Note :
//			Although the above answer is in lexicographical order, your answer could be in any order you want.
//
namespace Solution2
{
    namespace LetterCombinationsOfAPhoneNumber 
    {
		void impl(string digits, int level, vector<string>& candidates, string& result, vector<string>& results)
		{
			if (level == digits.length())
			{
				results.push_back(result);
				return;
			}
			string can = candidates[digits[level] - '0'];
			if (can.size() == 0) { impl(digits, level + 1, candidates, result, results); }

			for (char c : can)
			{
				result.push_back(c);
				impl(digits, level + 1, candidates, result, results);
				result.pop_back();
			}
		}


		vector<string> letterCombinations(string digits) {
			vector<string> can = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

			vector<string> results;
			int len = digits.length();

			if (len == 0) { return results; }
			string result;
			impl(digits, 0, can, result, results);
			return results;
		}
     
     
        void Main()
        {
			print(letterCombinations(""));
        }
    }
}
