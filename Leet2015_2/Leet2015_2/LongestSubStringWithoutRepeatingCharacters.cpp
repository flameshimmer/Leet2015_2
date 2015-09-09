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
		
		namespace test
		{
			int lengthOfLongestSubstring(string s) {
				int len = s.length();
				if (len < 2) { return len; }

				unordered_set<char> set;
				int start = 0;
				int end = 0;
				int result = 0;
				while (end < len)
				{
					while (end < len && set.find(s[end]) == set.end()) { set.insert(s[end]); end++; }
					result = max(result, end - start);

					while (s[start] != s[end]) { set.erase(s[start]); start++; }
					start++;
					end++;
				}
				result = max(result, end - start);
				return result;
			}
		}
        void Main()
        {
			print(test::lengthOfLongestSubstring("au"));
        }
    }
}
