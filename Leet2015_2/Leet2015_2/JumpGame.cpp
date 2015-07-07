#include "stdafx.h"

//Given an array of non - negative integers, you are 
//initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example :
//A = [2, 3, 1, 1, 4], return true.
//
//A = [3, 2, 1, 0, 4], return false.

namespace Solution2
{
    namespace JumpGame
    {     
		bool canJump(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return false; }
			if (len == 1) { return true; }

			int farest = 0;
			for (int i = 0; i < len; i++)
			{
				if (i>farest) { return false; }
				farest = max(farest, i + nums[i]);
			}
			return true;
		}
    
        void Main()
        {
         
        }
    }
}
