#include "stdafx.h"

//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//
namespace Solution2
{
    namespace ValidParentheses
    {
		bool matches(char o, char c)
		{
			if (o == '{') { return c == '}'; }
			if (o == '(') { return c == ')'; }
			if (o == '[') { return c == ']'; }
			return false;
		}

		bool isValid(string s) 
		{
			int len = s.length();
			if (len == 0) { return true; }

			stack<char> stack;
			for (char c : s)
			{
				if (stack.empty() || c == '{' || c == '[' || c == '(')
				{
					stack.push(c);
				}
				else if (matches(stack.top(), c))
				{
					stack.pop();
				}
				else
				{
					return false;
				}
			}
			return stack.empty();
		}
     
        void Main()
        {
         
        }
    }
}
