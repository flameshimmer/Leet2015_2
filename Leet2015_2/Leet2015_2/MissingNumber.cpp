#include "stdafx.h"

//Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
//
//For example,
//Given nums = [0, 1, 3] return 2.
//
//Note:
//Your algorithm should run in linear runtime complexity.Could you implement it using only constant extra space complexity ?

namespace Solution2
{
	namespace MissingNumber
	{
		int missingNumber(vector<int>& nums) {
			int len = nums.size();

			for (int i = 0; i < len; i++)
			{
				if (nums[i] == i || nums[i] >= len) { continue; }
				swap(nums[i], nums[nums[i]]);
				i--;
			}
			for (int i = 0; i < len; i++) 
			{
				if (nums[i] != i) { return i; }
			}
			return len;
		}

		void Main()
		{
			vector<int> input;
			input = { 0, 1, 3 };
			print(missingNumber(input));

			input = { 0};
			print(missingNumber(input));
		}
	}
}
