#include "stdafx.h"

//Implement strStr().
//
//Returns the index of the first occurrence of needle in haystack, 
//or - 1 if needle is not part of haystack.

namespace Solution2
{
    namespace ImplementStrStr
    {     
		namespace bruteforce
		{

			int strStr(string s, string p) {
				int lens = s.size();
				int lenp = p.size();

				if (lens < lenp) { return -1; }

				for (int start = 0; start <= lens - lenp; start++)
				{
					int	i = start;
					int j = 0;

					while (i < lens && j < lenp)
					{
						if (s[i] != p[j]) { break; }
						i++;
						j++;
					}
					if (j == lenp) { return start; }
				}
				return -1;
			}
		}
     

		vector<int> calcTable(string p)
		{
			int len = p.length();
			if (len == 0) { return vector<int>(); }

			vector<int> next(len, 0);
			for (int i = 1; i < len; i++)
			{
				int j = next[i - 1];
				while (j>0 && p[i] != p[j])
				{
					j = next[j - 1];
				}
				if (p[i] == p[j]) { j++; }
				next[i] = j;
			}
			return next;
		}

		int strStr(string s, string p)
		{
			int lens = s.length();
			int lenp = p.length();

			if (lens < lenp) { return -1; }

			vector<int> next = calcTable(p);
			int i = 0;
			int j = 0;
			while (i < lens && j < lenp)
			{
				while (j > 0 && s[i] != p[j])
				{
					j = next[j - 1];
				}
				if (s[i] == p[j]) { j++; }
				i++;
			}
			if (j == lenp) { return i - j; }
			return -1;
		}


        void Main()
        {
         
        }
    }
}
