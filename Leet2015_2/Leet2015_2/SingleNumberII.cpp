#include "stdafx.h"


//Given an array of integers, every element appears three times except for one.Find that single one.
//
//Note:
//Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?

namespace Solution2
{
    namespace SingleNumberII
    {     
		int singleNumber(vector<int>& nums) {
			int ones = 0;
			int twos = 0;
			int threes = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				twos |= ones & nums[i];
				ones ^= nums[i];
				threes = ones & twos;
				ones &= ~threes;
				twos &= ~threes;
			}
			return ones;
		}
     
        void Main()
        {
         
        }
    }
}
