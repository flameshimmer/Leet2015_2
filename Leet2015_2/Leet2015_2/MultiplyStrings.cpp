#include "stdafx.h"

//Given two numbers represented as strings, 
//return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non - negative.

namespace Solution2
{
    namespace MultiplyStrings
    {
     
		string add(string num1, string num2)
		{
			if (num1 == "0" || num2 == "0") { return num1 == "0" ? num2 : num1; }
			int len1 = num1.length();
			int len2 = num2.length();
			int carry = 0;
			string result;
			int i1 = len1 - 1;
			int i2 = len2 - 1;

			while (i1 >= 0 || i2 >= 0 || carry > 0)
			{
				int d1 = i1 >= 0 ? num1[i1] - '0' : 0;
				int d2 = i2 >= 0 ? num2[i2] - '0' : 0;
				int sum = d1 + d2 + carry;
				result.insert(result.begin(), sum % 10 + '0');
				carry = sum / 10;
				i1--;
				i2--;
			}
			return result;
		}

		string mul(string num1, char c)
		{
			if (num1 == "0" || c == '0') { return "0"; }
			int i = num1.length() - 1;
			int carry = 0;
			int cv = c - '0';
			string result;
			while (i >= 0 || carry > 0)
			{
				int val = (i >= 0 ? (num1[i] - '0') * cv : 0) + carry;
				result.insert(result.begin(), val % 10 + '0');
				carry = val / 10;
				i--;
			}
			return result;
		}

		string multiply(string num1, string num2) 
		{
			if (num1 == "0" || num2 == "0") { return "0"; }

			int len1 = num1.length();
			int len2 = num2.length();
			string result = "0";
			string append = "";
			for (int i = len2 - 1; i >= 0; i--)
			{
				char c = num2[i];
				string mulResult = mul(num1, c) + append;
				result = add(result, mulResult);
				append.push_back('0');
			}
			return result;
		}
     
     
        void Main()
        {
			print(multiply("1", "1"));
        }
    }
}
