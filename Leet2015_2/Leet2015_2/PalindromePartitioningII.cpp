#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return the minimum cuts needed for a palindrome partitioning of s.
//
//For example, given s = "aab",
//Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.
//

namespace Solution2
{
    namespace PalindromePartitioningII
    {
     
		int minCut(string s)
		{
			int len = s.length();
			if (len == 0) { return 0; }

			vector<int> D(len + 1);
			for (int i = 0; i < len + 1; i++)
			{
				D[i] = len - i - 1; // len-1 - i + 1 - 1
			}

			vector<vector<bool>> P(len + 1, vector<bool>(len + 1, false));

			for (int i = len - 1; i >= 0; i--)
			{
				for (int j = i; j < len; j++)
				{
					if (s[i] == s[j] && (j - i < 2 || P[i + 1][j - 1]))
					{
						P[i][j] = true;
						D[i] = min(D[i], D[j + 1] + 1);
					}
				}
			}
			return D[0];
		}
     
        void Main()
        {
			print(minCut(string("aab")));
        }
    }
}
