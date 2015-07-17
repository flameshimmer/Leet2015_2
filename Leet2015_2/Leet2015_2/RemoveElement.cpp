#include "stdafx.h"

//Given an array and a value, remove all instances of that value in place and return the new length.
//
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.

namespace Solution2
{
    namespace RemoveElement
    {     
		int removeElement(vector<int>& nums, int val) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }

			int slow = 0;
			int fast = 0;
			while (fast < len)
			{
				if (nums[fast] != val)
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
