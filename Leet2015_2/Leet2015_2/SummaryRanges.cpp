#include "stdafx.h"

//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given[0, 1, 2, 4, 5, 7], return["0->2", "4->5", "7"].

namespace Solution2
{
    namespace SummaryRanges
    {
     
		vector<string> summaryRanges(vector<int>& nums) 
		{
			vector<string> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int start = 0;
			while (start < len)
			{
				int end = start + 1;
				while (end < len && nums[end] == nums[end - 1] + 1) { end++; }
				end--;

				if (start != end)
				{
					result.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
				}
				else
				{
					result.push_back(to_string(nums[start]));
				}
				start = end + 1;
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
