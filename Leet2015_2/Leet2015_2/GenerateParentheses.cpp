#include "stdafx.h"

//Given n pairs of parentheses, write a function to 
//generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//"((()))", "(()())", "(())()", "()(())", "()()()"

namespace Solution2
{
    namespace GenerateParentheses
    {
		
		void generate(int n, int start, int end, string& result, vector<string>& results)
		{
			if (start == n && end == n)
			{
				results.push_back(result);
				return;
			}

			if (start < n)
			{
				result.push_back('(');
				generate(n, start + 1, end, result, results);
				result.pop_back();
			}

			if (end < n && end < start)
			{
				result.push_back(')');
				generate(n, start, end + 1, result, results);
				result.pop_back();
			}
		}
		
		
		vector<string> generateParenthesis(int n) 
		{
			vector<string> results;
			if (n == 0) { return results; }
			string result;
			generate(n, 0, 0, result, results);
			return results;
		}
     
        void Main()
        {
			print(generateParenthesis(3));
        }
    }
}
