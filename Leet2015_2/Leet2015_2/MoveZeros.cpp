#include "stdafx.h"

//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
//
//Note:
//You must do this in - place without making a copy of the array.
//Minimize the total number of operations.

namespace Solution2
{
	namespace MoveZeros
	{
		void moveZeroes(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return; }

			int slow = 0;
			int fast = 0;
			while (fast < len)
			{
				if (nums[fast] != 0)
				{
					nums[slow] = nums[fast];
					slow++;
				}
				fast++;
			}
			while (slow < len) { nums[slow] = 0; slow++; }
		}

		void Main()
		{
			vector<int> input = { 0, 1, 0, 3, 12 };
			moveZeroes(input);
			print(input);
		}
	}
}
