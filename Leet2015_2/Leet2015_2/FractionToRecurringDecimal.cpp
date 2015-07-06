#include "stdafx.h"

//Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//If the fractional part is repeating, enclose the repeating part in parentheses.
//
//For example,
//
//Given numerator = 1, denominator = 2, return "0.5".
//Given numerator = 2, denominator = 1, return "2".
//Given numerator = 2, denominator = 3, return "0.(6)".

namespace Solution2
{
    namespace FractionToRecurringDecimal
    {
		string fractionToDecimal(int numerator, int denominator) 
		{
			if (numerator == 0) { return "0"; }
			string result = "";
			bool isNeg = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
			long long num = numerator; 
			if (num < 0) { num *= -1; }
			long long de = denominator;
			if (de < 0) { de *= -1; }
			bool hasDot = false;
			unordered_map<int, int> map;

			while (num)
			{
				result += to_string(num / de);

				long long remain = num % de * 10;
				if (remain > 0 && !hasDot) { result += "."; hasDot = true; }

				if (map.find(remain) == map.end())
				{
					map[remain] = result.size();
					num = remain;
				}
				else
				{
					result.insert(result.begin() + map[remain], '(');
					result += ")";
					break;
				}
			}
			if (isNeg) { result = "-" + result; }
			return result;
		}
     
        void Main()
        {
			print(fractionToDecimal(0, 3));
        }
    }
}
