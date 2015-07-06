#include "stdafx.h"

//Given a string S and a string T, count the number of distinct subsequences of T in S.
//
//A subsequence of a string is a new string which is formed from the original string by
//deleting some(can be none) of the characters without disturbing the relative positions
//of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Here is an example :
//S = "rabbbit", T = "rabbit"
//
//Return 3.

namespace Solution2
{
    namespace DistinctSubsequences
    {     
		int numDistinct(string s, string t) 
		{
			int lens = s.length();
			int lent = t.length();
			vector<int> M(lent + 1, 0);
			M[0] = 1;
			for (int i = 1; i < lens + 1; i++)
			{
				for (int j = lent; j >= 1; j--)
				{
					if (s[i - 1] == t[j - 1]) { M[j] += M[j - 1]; }
				}
			}
			return M[lent];
		}     
     
        void Main()
        {
         
        }
    }
}
