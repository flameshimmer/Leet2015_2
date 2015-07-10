#include "stdafx.h"

//Given an array of size n, find the majority element.
//The majority element is the element that appears more than ⌊ n / 2 ⌋ times.
//
//You may assume that the array is non - empty and the majority element always exist in the array.

namespace Solution2
{
    namespace MajorityElement
    {
     
		int majorityElement(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return -1; }
			int result = nums[0];
			int count = 0;

			for (int val : nums)
			{
				if (val == result) { count++; }
				else
				{
					count--;
					if (count == 0)
					{
						count = 1;
						result = val;
					}
				}
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
