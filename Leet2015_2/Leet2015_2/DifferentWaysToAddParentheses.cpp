#include "stdafx.h"

//Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
//The valid operators are +, - and *.
//
//
//Example 1
//Input: "2-1-1".
//
//((2-1)-1) = 0
//(2-(1-1)) = 2
//Output: [0, 2]
//
//
//Example 2
//Input: "2*3-4*5"
//
//(2*(3-(4*5))) = -34
//((2*3)-(4*5)) = -14
//((2*(3-4))*5) = -10
//(2*((3-4)*5)) = -10
//(((2*3)-4)*5) = 10
//Output: [-34, -14, -10, -10, 10]

namespace Solution2
{
	namespace DifferentWaysToAddParentheses
	{
		struct token
		{
			bool isNum;
			int num;
			char sign;
			token(string& s, int start, int end)
			{				
				if (start == end)
				{
					if (!isdigit(s[start])) { isNum = false; sign = s[start]; return; }
				}

				isNum = true;
				num = 0;
				while (start <= end)
				{
					num = num * 10 + s[start] - '0';
					start++;
				}
			}
		};

		vector<int> impl(vector<token>& tokens, int start, int end)
		{
			vector<int> result;
			int lent = tokens.size();
			if (start == end && tokens[start].isNum) { result.push_back(tokens[start].num); return result; }
			for (int i = start; i <= end; i++)
			{
				if (tokens[i].isNum) { continue; }
				vector<int> lefts = impl(tokens, start, i - 1);
				vector<int> rights = impl(tokens, i + 1, end);
				for (int l : lefts)
				{
					for (int r : rights)
					{
						if (tokens[i].sign == '+') { result.push_back(l + r); }
						else if (tokens[i].sign == '-') { result.push_back(l - r); }
						else if (tokens[i].sign == '*') { result.push_back(l * r); }
						else if (tokens[i].sign == '/') { result.push_back(l / r); }
					}
				}
			}
			return result;
		}

		vector<int> diffWaysToCompute(string input) {
			vector<int> result;
			int len = input.size();
			if (len == 0) { return result; }

			vector<token> tokens;
			int start = 0;
			while (start < len)
			{
				int end = start + 1;
				while (end < len && isdigit(input[end])) { end++; }
				end--;
				tokens.push_back(token(input, start, end));
				if (end + 1 < len)
				{
					tokens.push_back(token(input, end + 1, end + 1));
				}
				start = end + 2;
			}
			return impl(tokens, 0, tokens.size() - 1);
		}

		void Main()
		{
			print(diffWaysToCompute("11"));
			print(diffWaysToCompute("2-1-1"));
		}
	}
}
