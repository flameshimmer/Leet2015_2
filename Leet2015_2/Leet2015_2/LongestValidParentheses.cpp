#include "stdafx.h"

//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

namespace Solution2
{
    namespace LongestValidParentheses
    {
     
		int longestValidParentheses(string s)
		{
			int len = s.length();
			if (len < 2) { return 0; }

			stack<pair<char, int>> stack;
			s = ")" + s;
			int longest = 0;
			for (int i = 0; i < len + 1; i++)
			{
				char c = s[i];
				if (stack.empty() || c == '(' || (c == ')' && stack.top().first != '('))
				{
					stack.push(make_pair(c, i));
				}
				else
				{
					stack.pop();
					longest = max(longest, i - stack.top().second);
				}
			}
			return longest;
		}
     
     
        void Main()
        {
			print(longestValidParentheses(")("));
        }
    }
}
