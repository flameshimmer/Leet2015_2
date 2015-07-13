#include "stdafx.h"

//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//For example,
//S = "ADOBECODEBANC"
//T = "ABC"
//Minimum window is "BANC".
//
//Note:
//If there is no such window in S that covers all characters in T, return the emtpy string "".
//
//If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


namespace Solution2
{
    namespace MinimumWindowSubstring
    {
		string minWindow(string s, string t) 
		{
			int lens = s.size();
			int lent = t.size();
			if (lens < lent || lent == 0) { return ""; }

			unordered_map<char, int> toBeFound;
			unordered_map<char, int> hasFound;
			int found = 0;
			int start = 0;
			int end = 0;

			int minLen = INT_MAX;
			int startPos = -1;

			for (char c : t)
			{
				toBeFound[c]++;
			}

			while (end < lens)
			{
				while (end < lens)
				{
					char c = s[end];
					if (toBeFound.find(c) != toBeFound.end())
					{
						if (hasFound[c] < toBeFound[c]) { found++; }
						hasFound[c]++;
					}
					if (found == lent) { break; }
					end++;
				}

				while (start <= end && end != lens)
				{
					char c = s[start];
					if (hasFound.find(c) != hasFound.end())
					{
						hasFound[c]--;
						if (hasFound[c] < toBeFound[c])
						{
							found--;
							int len = end - start + 1;
							if (len < minLen)
							{
								minLen = len;
								startPos = start;
							}
							start++;
							break;
						}
					}
					start++;
				}
				end++;
			}
			return startPos == -1 ? "" : s.substr(startPos, minLen);
		}
     
        void Main()
        {
			print(minWindow("adobecodebanc", "abcda"));
			print(minWindow("cabefgecdaecf", "cae"));
			print(minWindow("aa", "aa"));
			print(minWindow("ab", "a"));
			print(minWindow("ADOBECODEBANC", "ABC"));
        }
    }
}
