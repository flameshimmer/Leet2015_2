#include "stdafx.h"

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
//like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string text, int nRows);
//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

namespace Solution2
{
    namespace ZigZagConversion
    {     
		string convert(string s, int numRows) {
			if (numRows == 1) { return s; }

			int lens = s.length();
			int distance = (numRows - 1) * 2;
			string result;
			for (int i = 0; i < lens; i += distance)
			{
				result.push_back(s[i]);
			}
			
			for (int i = 1; i <= numRows - 2; i++)
			{
				int gap = 2 * i;
				for (int j = i; j < lens; j += gap)
				{
					result.push_back(s[j]);
					gap = distance - gap;
				}
			}
			for (int i = numRows - 1; i < lens; i+= distance)
			{
				result.push_back(s[i]);
			}
			return result;
		}
     
        void Main()
        {
			print(convert("ABCD", 4));
			print(convert("PAYPALISHIRING", 3));
        }
    }
}
