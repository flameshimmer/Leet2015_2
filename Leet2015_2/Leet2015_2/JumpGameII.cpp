#include "stdafx.h"

//Given an array of non - negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Your goal is to reach the last index in the minimum number of jumps.
//
//For example :
//Given array A = [2, 3, 1, 1, 4]
//
//The minimum number of jumps to reach the last index is 2. 
//(Jump 1 step from index 0 to 1, then 3 steps to the last index.)

namespace Solution2
{
    namespace JumpGameII
    {
     
		int jump(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }
			
			int start = 0;
			int end = 0;
			int reach = 0;
			int count = 0;
			while (reach < len-1)
			{
				count++;
				for (int i = start; i <= end; i++)
				{
					reach = max(reach, nums[i] + i);
				}
				start = end + 1;
				end = reach;
			}
			return count;
		}
     
        void Main()
        {
         
        }
    }
}
