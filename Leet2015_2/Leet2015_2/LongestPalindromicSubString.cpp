#include "stdafx.h"

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


namespace Solution2
{
    namespace LongestPalindromicSubString
    {
		string longestPalindrome(string s) 
		{
			int len = s.length();
			if (len < 2) { return s; }

			int begin = 0;
			int longest = 0;

			for (int i = 0; i<len; i++)
			{
				int start = i;
				while (i + 1 < len && s[i] == s[i + 1]) { i++; }
				int end = i;

				while (start >= 0 && end < len && s[start] == s[end])
				{
					start--;
					end++;
				}
				if (end - start - 1 > longest) { longest = end - start - 1; begin = start + 1; }
			}
			return s.substr(begin, longest);
		}
     
        void Main()
        {
			print(longestPalindrome("bb"));
        }
    }
}
