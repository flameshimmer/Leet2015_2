#include "stdafx.h"

//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

namespace Solution2
{
    namespace LongestSubstringWithAtMostTwoDistinctCharacters
    {
     
		int lengthOfLongestSubstringTwoDistinct(string s) 
		{
			int len = s.length();
			if (len <= 2) { return len; }

			pair<char, pair<int, int>> map[2];
			map[0] = make_pair(NULL, make_pair(0, 0));
			map[1] = make_pair(NULL, make_pair(0, 0));
			int filled = 0;
			int longest = 0;
			for (int i = 0; i < len; i++)
			{
				char c = s[i];
				if (map[0].first == c || map[1].first == c)
				{
					map[0].first == c ? map[0].second.second = i : map[1].second.second = i;
				}
				else if (filled < 2)
				{
					map[filled] = make_pair(c, make_pair(i, i));
					filled++;
				}
				else
				{
					longest = max(longest, i - min(map[0].second.first, map[1].second.first));
					int index = (map[0].second.second) == i - 1 ? 1 : 0;
					int otherIndex = index == 1 ? 0 : 1;
					map[otherIndex].second.first = map[index].second.second + 1;
					map[index] = make_pair(c, make_pair(i, i));
				}
			}
			longest = max(longest, 1 + max(map[0].second.second, map[1].second.second) - min(map[0].second.first, map[1].second.first));
			return longest;
		}
     
        void Main()
        {
			print(lengthOfLongestSubstringTwoDistinct("abacd"));
			print(lengthOfLongestSubstringTwoDistinct("aaaa"));
			print(lengthOfLongestSubstringTwoDistinct("aac"));
        }
    }
}
