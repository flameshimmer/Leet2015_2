#include "stdafx.h"

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, 
//or - 1 if needle is not part of haystack.

namespace Solution2
{
    namespace ImplementStrStr
    {
     
		int strStr(string s, string p) {
			int lens = s.size();
			int lenp = p.size();

			if (lens < lenp) { return -1; }


			for (int start = 0; start <= lens-lenp; start++)
			{
				int	i = start;
				int j = 0;

				while (i < lens && j<lenp)
				{
					if (s[i] != p[j]) { break; }
					i++;
					j++;
				}
				if (j == lenp) { return start; }
			}
			return -1;
		}
     
     
        void Main()
        {
         
        }
    }
}
