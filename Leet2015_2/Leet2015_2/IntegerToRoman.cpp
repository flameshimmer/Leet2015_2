#include "stdafx.h"

//Given an integer, convert it to a roman numeral.
//
//Input is guaranteed to be within the range from 1 to 3999.
//
//Symbols are placed from left to right in order of value, starting with the largest.However, 
// in a few specific cases, to avoid four characters being repeated in succession(such as IIII or XXXX)
// these can be reduced using subtractive notation as follows:
//
//the numeral I can be placed before V and X to make 4 units(IV) and 9 units(IX) respectively
//X can be placed before L and C to make 40 (XL)and 90 (XC)respectively
//C can be placed before D and M to make 400 (CD)and 900 (CM)according to the same pattern[5]
//
//An example using the above rules would be 1904 : this is composed of 1 (one thousand), 
//9 (nine hundreds), 0 (zero tens), and 4 (four units).To write the Roman numeral, each of the non-zero 
// digits should be treated separately.Thus 1000 = M, 900 = CM, and 4 = IV.Therefore, 1904 is MCMIV.
//
//Symbol Value
//I	1
//V	5
//X	10
//L	50
//C	100
//D	500
//M	1000

namespace Solution2
{
    namespace IntegerToRoman
    {
		string intToRoman(int num) 
		{
			vector<pair<int, string>> data = { 
				make_pair(1, "I"),
				make_pair(4, "IV"),
				make_pair(5, "V"),
				make_pair(9, "IX"),
				make_pair(10, "X"),
				make_pair(40, "XL"),
				make_pair(50, "L"),
				make_pair(90, "XC"),
				make_pair(100, "C"),
				make_pair(400, "CD"),
				make_pair(500, "D"),
				make_pair(900, "CM"),
				make_pair(1000, "M")
			};

			string result;
			int index = data.size() - 1;
			while (num)
			{
				if (num < data[index].first) { index--; continue; }
				int count = num / data[index].first;
				for (int i = 0; i < count; i++)
				{
					result += data[index].second;
				}
				num %= data[index].first;
				index--;
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
