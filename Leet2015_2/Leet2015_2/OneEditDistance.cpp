#include "stdafx.h"

//Given two strings S and T, determine if they are both one edit distance apart.
//Replacement cost is counted as 1

namespace Solution2
{
    namespace OneEditDistance
    {
     
		bool isOneEditDistance(string s, string t) 
		{
			if (s.length() < t.length()) { swap(s, t); }
			int lens = s.length();
			int lent = t.length();
			if (lens - lent > 1) { return false; }

			int i1 = 0;
			int i2 = 0;
			int count = 0;
			while (i1 < lens || i2 < lent)
			{
				if (i1 >= lens || i2 >= lent || s[i1] != t[i2])
				{
					count++;
					if (count > 1) { return false; }
					if (lens == lent) { i2++; }
					i1++;
				}
				else
				{
					i1++;
					i2++;
				}
			}
			return count == 1;
		}
     
     
        void Main()
        {
			print(isOneEditDistance("a", ""));
			print(isOneEditDistance("teacher", "detacher"));
			print(isOneEditDistance("", "A"));
        }
    }
}
