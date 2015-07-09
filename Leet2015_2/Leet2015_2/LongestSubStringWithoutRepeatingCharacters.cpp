#include "stdafx.h"


//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
//which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

namespace Solution2
{
    namespace LongestSubStringWithoutRepeatingCharacters
    {
		int lengthOfLongestSubstring(string s) 
		{
			int len = s.length();
			if (len < 2) { return len; }

			int start = 0;
			int end = 0;
			int longest = 0;
			int map[256];
			memset(map, -1, sizeof(map));
			while (end < len)
			{
				char c = s[end];
				if (map[c] == -1) { map[c] = end; }
				else
				{
					longest = max(longest, end - start);
					start = max(start, map[c] + 1);
					map[c] = end;
				}
				end++;
			}
			longest = max(longest, end - start);
			return longest;
		}
     
        void Main()
        {
			print(lengthOfLongestSubstring("au"));
        }
    }
}
