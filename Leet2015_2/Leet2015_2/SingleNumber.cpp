#include "stdafx.h"

//Given an array of integers, every element appears twice except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory?

namespace Solution2
{
    namespace SingleNumber
    {     
		int singleNumber(vector<int>& nums) 
		{
			int result = nums[0];
			for (int i = 1; i < nums.size(); i++)
			{
				result ^= nums[i];
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
