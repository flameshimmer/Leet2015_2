#include "stdafx.h"

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
//for example: "ACGAATTCCG".When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
//
//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.
//
//For example,
//
//Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
//
//Return:
//["AAAAACCCCC", "CCCCCAAAAA"].

namespace Solution2
{
    namespace RepeatedDNASequences
    {
		vector<string> findRepeatedDnaSequences(string s) 
		{
			vector<string> result;
			int len = s.length();
			if (len < 10) { return result; }

			unordered_map<int, int> map; // key, count
			for (int i = 0; i < len - 9; i++)
			{
				int key = 0;
				for (int j = i; j < i + 10; j++)
				{
					key <<= 2;
					int m = (s[j] - 'A' + 1)%5;
					key |= m;
				}
				map[key]++;
				if (map[key] == 2)
				{
					result.push_back(s.substr(i, 10));
				}
			}
			return result;
		}
     
        void Main()
        {
			print(findRepeatedDnaSequences("AAAAAAAAAAA"));
        }
    }
}
