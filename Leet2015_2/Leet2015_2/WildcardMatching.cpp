#include "stdafx.h"

//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//
//The matching should cover the entire input string(not partial).
//
//The function prototype should be :
//bool isMatch(const char *s, const char *p)
//
//Some examples :
//isMatch("aa", "a") → false
//isMatch("aa", "aa") → true
//isMatch("aaa", "aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

namespace Solution2
{
    namespace WildcardMatching
    {
		bool isMatch(const char* s, const char* p)
		{
			const char* star = NULL;
			const char* ss = s;
			while (*s)
			{
				if (*p == *s || *p == '?') { p++; s++; continue; }
				if (*p == '*') { star = p++; ss = s; continue; }
				if (star) { p = star + 1; s = ++ss; continue; }
				return false;
			}
			while (*p == '*') { p++; }
			return !*p;
		}

		bool isMatch(string s, string p) {
			return isMatch(s.c_str(), p.c_str());
		}

		namespace DP
		{
			bool isMatch(string s, string p) 
			{
				int lens = s.length();
				int lenp = p.length();
				
				vector<vector<bool>> M(lens + 1, vector<bool>(lenp + 1));
				M[0][0] = true;

				for (int i = 1; i < lenp + 1 && p[i-1] == '*'; i++)
				{
					M[0][i] = true;
				}

				for (int i = 1; i < lens + 1; i++)
				{
					for (int j = 1; j < lenp + 1; j++)
					{
						if (s[i - 1] == p[j - 1] || p[j-1] == '?') { M[i][j] = M[i - 1][j - 1]; }
						else if (p[j - 1] == '*') { M[i][j] = M[i - 1][j] || M[i][j - 1]; }
					}
				}
				return M[lens][lenp];
			}
		}
     
        void Main()
        {
			isMatch("aa", "a");
			isMatch("aa", "aa");
			isMatch("aaa", "aa");
			isMatch("aa", "*");
			isMatch("aa", "a*");
			isMatch("ab", "?*");
			isMatch("aab", "c*a*b");
        }
    }
}
