#include "stdafx.h"

//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases.If you want a challenge, 
//	  please do not see below and ask yourself what are the possible input cases.
//
//  Notes : It is intended for this problem to be specified vaguely
//		  (ie, no given input specs).You are responsible to gather all the input requirements up front.
//
//Requirements for atoi:
//The function first discards as many whitespace characters as necessary 
//until the first non - whitespace character is found.Then, starting from this character, 
//takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
//and interprets them as a numerical value.
//
//The string can contain additional characters after those that form the integral number, 
//which are ignored and have no effect on the behavior of this function.
//
//If the first sequence of non - whitespace characters in str is not a valid integral number, 
//or if no such sequence exists because either str is empty or it contains only whitespace 
//characters, no conversion is performed.
//
//If no valid conversion could be performed, a zero value is returned.If the correct value
//is out of the range of representable values, INT_MAX(2147483647) or INT_MIN(-2147483648) is returned.

namespace Solution2
{
    namespace StringToInteger
    {
		bool isNum(char c)
		{
			return c >= '0' && c <= '9';
		}

		int myAtoi(string str) {
			int len = str.length();
			if (len == 0) { return 0; }

			int start = 0;
			while (start < len && str[start] == ' ') { start++; }
			if (str[start] != '+' && str[start] != '-' && !isNum(str[start])) { return 0; }
			
			int sign = 1;
			if (str[start] == '-') { sign = -1; }
			if (str[start] == '+' || str[start] == '-') { start++; }
			
			long long result = 0;
			while (start < len && isNum(str[start]))
			{
				result = result * 10 + sign * (str[start] - '0');
				if (result > INT_MAX) { return INT_MAX; }
				if (result < INT_MIN) { return INT_MIN; }
				start++;
			}
			return (int)result;
		}
     
     
        void Main()
        {
         
        }
    }
}
