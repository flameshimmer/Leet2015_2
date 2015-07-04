#include "stdafx.h"

//Given an array of integers, find if the array contains any duplicates.
//Your function should return true if any value appears at least twice in the array, 
//and it should return false if every element is distinct.

namespace Solution2
{
    namespace ContainsDuplicate
    {
     
		bool containsDuplicate(vector<int>& nums) 
		{
			int len = nums.size();
			if (len < 2) { return false; }

			unordered_set<int> set;
			for (int val : nums)
			{
				if (set.find(val) != set.end()) { return true; }
				set.insert(val);
			}
			return false;
		}     
     
        void Main()
        {
         
        }
    }
}
