#include "stdafx.h"

//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
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
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

namespace Solution2
{
    namespace RegularExpressionMatching
    {
		namespace recursion{
			bool matches(string& s, string& p, int i, int j, int lens, int lenp)
			{
				return i < lens && j < lenp && (s[i] == p[j] || p[j] == '.');
			}
			bool isMatches(string& s, string& p, int i, int j, int lens, int lenp)
			{
				if (j >= lenp) { return i >= lens; }

				if (j + 1 >= lenp || p[j + 1] != '*')
				{
					return matches(s, p, i, j, lens, lenp) && isMatches(s, p, i + 1, j + 1, lens, lenp);
				}


				while (matches(s, p, i, j, lens, lenp))
				{
					if (isMatches(s, p, i, j + 2, lens, lenp)) { return true; }
					i++;
				}
				return isMatches(s, p, i, j + 2, lens, lenp);
			}
			bool isMatch(string s, string p) {
				int lens = s.length();
				int lenp = p.length();
				return isMatches(s, p, 0, 0, lens, lenp);
			}
		}
		
		bool matches(string& s, string& p, int i, int j)
		{
			return s[i] == p[j] || p[j] == '.';
		}

		bool isMatch(string s, string p) {
			int lens = s.length();
			int lenp = p.length();

			vector<vector<bool>>M(lens + 1, vector<bool>(lenp + 1, false));
			M[0][0] = true;

			for (int i = 0; i < lens+1; i++)
			{
				for (int j = 1; j < lenp + 1; j++)
				{
					if (i>=1 && matches(s, p, i - 1, j - 1) && M[i - 1][j - 1])
					{
						M[i][j] = true;
						continue;
					}
					if (j>=2 && i>=1 && p[j - 1] == '*' && matches(s, p, i - 1, j - 2) && M[i - 1][j])
					{
						M[i][j] = true;
						continue;
					}
					if (j>=2 && p[j - 1] == '*' && M[i][j - 2])
					{
						M[i][j] = true;
						continue;
					}
				}
			}
			return M[lens][lenp];
		}
     
        void Main()
        {
			print(isMatch("aa", "a*"));
			print(isMatch("aa", "a"));
			print(isMatch("a", "..a*"));
			print(isMatch("a", "ab*"));
			
        }
    }
}
