#include "stdafx.h"

//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

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
    namespace RomanToInteger
    {     
		int romanToInt(string s) {
			unordered_map<char, int>map;
			map['I'] = 1;
			map['V'] = 5;
			map['X'] = 10;
			map['L'] = 50;
			map['C'] = 100;
			map['D'] = 500;
			map['M'] = 1000;

			int result = 0;
			int len = s.length();
			for (int i = 0; i < len; i++)
			{
				if (i + 1 < len && map[s[i]] < map[s[i + 1]])
				{
					result += map[s[i + 1]] - map[s[i]];
					i++;
				}
				else
				{
					result += map[s[i]];
				}
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
