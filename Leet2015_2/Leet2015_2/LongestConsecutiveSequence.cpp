#include "stdafx.h"


//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//For example,
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//
//Your algorithm should run in O(n) complexity.


namespace Solution2
{
    namespace LongestConsecutiveSequence
    {

		int longestConsecutive(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return len; }
			
			unordered_set<int> set(nums.begin(), nums.end());

			int longest = 0;
			for (int i : nums)
			{
				if (set.find(1) == set.end()) { continue; }
				set.erase(i);
				int start = i-1;
				while (set.find(start) != set.end()) { set.erase(start); start--; }

				int end = i+1;
				while (set.find(end) != set.end()) { set.erase(end); end++; }
				longest = max(longest, end - start - 1);
			}
			return longest;
		}
     
        void Main()
        {
			vector<int> input;
			input = { -1, 1, 0 };
			print(longestConsecutive(input));

			input = { -1, 1, 2, 0 };
			print(longestConsecutive(input));
			
			input = { 100, 4, 200, 1, 3, 2 };
			print(longestConsecutive(input));
        }
    }
}
