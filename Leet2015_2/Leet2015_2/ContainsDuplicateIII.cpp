#include "stdafx.h"

//Given an array of integers, find out whether there are two distinct indices i and j in 
//the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

namespace Solution2
{
    namespace ContainsDuplicateIII
    {
		bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
		{
			int len = nums.size();
			if (k < 0 || t < 0 || len < 2) { return false; }

			set<int> set;
			for (int i = 0; i < len; i++)
			{
				if (i > k)
				{
					set.erase(nums[i-k-1]);
				}

				auto it = set.lower_bound(nums[i] - t);
				if (it != set.end() && abs(*it - nums[i]) <= t) { return true; }
				set.insert(nums[i]);
			}
			return false;
		}

        
		void Main()
        {
			print(containsNearbyAlmostDuplicate(createVector({ 1, 2 }), 0, 1));
			print(containsNearbyAlmostDuplicate(createVector({1, 1, 1}), 2, 0));
        }
    }
}
