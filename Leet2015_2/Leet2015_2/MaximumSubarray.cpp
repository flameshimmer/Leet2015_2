#include "stdafx.h"

//Find the contiguous subarray within an array(containing at least one number)
//which has the largest sum.
//
//For example, given the array[−2, 1, −3, 4, −1, 2, 1, −5, 4],
//the contiguous subarray[4, −1, 2, 1] has the largest sum = 6.

namespace Solution2
{
    namespace MaximumSubarray
    {     
		int maxSubArray(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int maxSum = nums[0];
			int sum = nums[0];
			for (int i = 1; i < len; i++)
			{
				sum = max(0, sum) + nums[i];
				maxSum = max(maxSum, sum);
			}
			return maxSum;
		}
     
        void Main()
        {
         
        }
    }
}
