#include "stdafx.h"

//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//For example,
//Given:
//s1 = "aabcc",
//s2 = "dbbca",
//
//When s3 = "aadbbcbcac", return true.
//When s3 = "aadbbbaccc", return false.


namespace Solution2
{
    namespace InterleavingString
    {
     
		bool isInterleave(string s1, string s2, string s3) 
		{
			int len1 = s1.length();
			int len2 = s2.length();
			int len3 = s3.length();
			if (len1 + len2 != len3) { return false; }

			vector<bool>M(len2 + 1, false);
			M[0] = true;
			for (int i = 1; i < len2 + 1; i++)
			{
				M[i] = M[i - 1] && (s2[i - 1] == s3[i - 1]);
			}

			for (int i = 1; i < len1 + 1; i++)
			{
				M[0] = M[0] && s1[i - 1] == s3[i - 1];
				for (int j = 1; j < len2 + 1; j++)
				{
					bool op1 = M[j - 1] && (s2[j - 1] == s3[i + j - 1]);
					bool op2 = M[j] && (s1[i - 1] == s3[i + j - 1]);
					M[j] = op1 || op2;
				}
			}
			return M[len2];
		}
     
     
        void Main()
        {
			print(isInterleave("a", "", "c"));
			print(isInterleave("a", "b", "ab"));
			print(isInterleave("", "b", "b"));
			print(isInterleave("a", "", "a"));
        }
    }
}
