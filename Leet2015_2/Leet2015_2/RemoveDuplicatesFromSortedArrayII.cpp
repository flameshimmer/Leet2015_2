#include "stdafx.h"

//Follow up for "Remove Duplicates":
//What if duplicates are allowed at most twice ?
//
//For example,
//Given sorted array A = [1, 1, 1, 2, 2, 3],
//
//Your function should return length = 5, and A is now[1, 1, 2, 2, 3]

namespace Solution2
{
    namespace RemoveDuplicatesFromSortedArrayII
    {
     
		int removeDuplicates(vector<int>& nums) {
			int len = nums.size();
			if (len < 3) { return len; }

			int slow = 1;
			int fast = 1;
			int count = 1;
			while (fast < len)
			{
				if (nums[fast] != nums[fast - 1])
				{
					count = 0;
				}
				if (count < 2)
				{
					nums[slow] = nums[fast];
					slow++;
					count++;
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
