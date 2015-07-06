#include "stdafx.h"


//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Some examples :
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//

namespace Solution2
{
    namespace EvaluateReversePolishNotation
    {
		int evalRPN(vector<string>& tokens) {
			int len = tokens.size();
			if (len == 0) { return 0; }

			stack<int> stack;
			for (string s : tokens)
			{
				if (s == "+" || s == "-" || s == "*" || s == "/")
				{
					int op1 = stack.top();
					stack.pop();
					int op2 = stack.top();
					stack.pop();
					if (s == "+") { stack.push(op2 + op1); }
					else if (s == "-") { stack.push(op2 - op1); }
					else if (s == "*") { stack.push(op2 * op1); }
					else { stack.push(op2 / op1); }
				}
				else
				{
					int val = 0;
					bool isNeg = false;
					for (char c : s)
					{
						if (c == '-') {isNeg = true;}
						val = val * 10 + (c - '0');
					}
					if (isNeg) { val *= -1; }
					stack.push(val);
				}
			}
			return stack.top();
		}     
     
        void Main()
        {
			vector<string> input = {"0", "3", "/"};
			print(evalRPN(input));
        }
    }
}
