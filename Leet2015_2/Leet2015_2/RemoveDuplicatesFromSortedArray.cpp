#include "stdafx.h"

//Given a sorted array, remove the duplicates in place such 
//that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//Given input array A = [1, 1, 2],
//
//Your function should return length = 2, and A is now[1, 2].

namespace Solution2
{
    namespace RemoveDuplicatesFromSortedArray
    {
     
		int removeDuplicates(vector<int>& nums) 
		{
			int len = nums.size();
			if (len < 2) { return len; }

			int slow = 1;
			int fast = 1;
			while (fast < len)
			{
				if (nums[fast] != nums[fast - 1])
				{
					nums[slow] = nums[fast];
					slow++;
				}
				fast++;
			}
			return slow;
		}
     
        void Main()
        {
         
        }
    }
}
