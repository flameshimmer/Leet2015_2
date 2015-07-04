#include "stdafx.h"

//Given an array of integers and an integer k, find out whether there there 
//are two distinct indices i and j in the array such that nums[i] = nums[j] 
//and the difference between i and j is at most k.

namespace Solution2
{
    namespace ContainsDuplicateII
    {
     
		bool containsNearbyDuplicate(vector<int>& nums, int k) 
		{
			int len = nums.size();
			if (len < 2) { return false; }

			unordered_map<int, int> map;
			for (int i = 0; i < len; i++)
			{
				int c = nums[i];
				if (map.find(c) == map.end())
				{
					map[c] = i;
				}
				else
				{
					if (i - map[c] <= k) { return true; }
					map[c] = i;
				}
			}
			return false;
		}
     
     
        void Main()
        {
         
        }
    }
}
