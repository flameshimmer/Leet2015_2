#include "stdafx.h"

//Given a string S, you are allowed to convert it to a palindrome by adding characters
//in front of it.Find and return the shortest palindrome you can find by performing this transformation.
//
//For example :
//
//Given "aacecaaa", return "aaacecaaa".
//
//Given "abcd", return "dcbabcd".

namespace Solution2
{
    namespace ShortestPalindrome
    {
		string shortestPalindrome(string s) 
		{
			int len = s.length();
			if (len < 2) { return s; }

			string rev = s;
			reverse(rev.begin(), rev.end());
			string l = s + "#" + rev;

			vector<int> next(l.size(), 0);
			for (int i = 1; i < l.size(); i++)
			{
				int j = next[i - 1];
				while (j > 0 && l[i] != l[j])
				{
					j = next[j - 1];
				}
				if (l[i] == l[j]) { j++; }
				next[i] = j;
			}

			int notFitLen = len - next[l.size() - 1];
			string fr = rev.substr(0, notFitLen);
			return fr + s;
		}
     
        void Main()
        {
			print(shortestPalindrome("abb"));
        }
    }
}
