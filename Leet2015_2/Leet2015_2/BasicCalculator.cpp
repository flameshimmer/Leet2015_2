#include "stdafx.h"

//Implement a basic calculator to evaluate a simple expression string.
//
//The expression string may contain open(and closing parentheses), the plus + or minus sign - , non - negative integers and empty spaces .
//
//You may assume that the given expression is always valid.
//
//Some examples :
//"1 + 1" = 2
//" 2-1 + 2 " = 3
//"(1+(4+5+2)-3)+(6+8)" = 23
//Note : Do not use the eval built - in library function

namespace Solution2
{
    namespace BasicCalculator
    {
     
		int calculate(string s) {
			int len = s.length();
			if (len == 0) { return 0; }

			int result = 0;
			int local = 1;
			int global = 1;
			stack<int> stack;
			for (int i = 0; i<len; i++)
			{
				char c = s[i];
				switch (c)
				{
				case '+':
				case ' ':
					break;
				case '-':
					local = -1;
					break;
				case '(':
					global *= local;
					stack.push(local);
					local = 1;
					break;
				case ')':
					global /= stack.top();
					stack.pop();
					local = 1;
					break;
				default:
					int val = 0;
					while (i<len && s[i] - '0' >= 0 && s[i] - '0' <= 9)
					{
						val = val * 10 + s[i] - '0';
						i++;
					}
					i--;
					result += global*local*val;
					local = 1;
					break;
				}
			}
			return result;
		}
     
        void Main()
        {
			print(calculate("(1)"));
			print(calculate("2147483647"));
        }
    }
}
