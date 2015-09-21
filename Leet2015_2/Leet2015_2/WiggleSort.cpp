#include "stdafx.h"

//Given an unsorted array nums, reorder it in - place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is[1, 6, 2, 5, 3, 4].

namespace Solution2
{
	namespace WiggleSort
	{
		void wiggleSort(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return; }
			bool smaller = true;

			for (int i = 0; i < len - 1; i++)
			{
				if ((smaller && (nums[i] > nums[i + 1])) || (!smaller && (nums[i] < nums[i + 1])))
				{
					swap(nums[i], nums[i + 1]);
				}
				smaller = !smaller;
			}
		}

		void Main()
		{
			vector<int> input = { 3, 5, 2, 1, 6, 4 };
			wiggleSort(input);
			print(input);
		}
	}
}
