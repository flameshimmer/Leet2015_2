#include "stdafx.h"

//Given an array with n objects colored red, white or blue, 
//sort them so that objects of the same color are adjacent, 
//with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent 
//the color red, white, and blue respectively.
//
//Note:
//You are not suppose to use the library's sort function for this problem.

namespace Solution2
{
    namespace SortColors
    {     
		void swap(vector<int>& nums, int a, int b)
		{
			int temp = nums[a];
			nums[a] = nums[b];
			nums[b] = temp;
		}
		void partition(vector<int>& nums, int pivotVal)
		{
			int i = 0;
			int len = nums.size();
			for (i; i < len; i++) { if (nums[i] == pivotVal) { break; } }
			if (i == len) { return; }
			swap(nums, i, len - 1);

			int slow = 0;
			int fast = 0;
			while (fast < len)
			{
				if (nums[fast] < pivotVal)
				{
					swap(nums, slow, fast);
					slow++;
				}
				fast++;
			}
			swap(nums, slow, len-1);
		}

		void sortColors(vector<int>& nums) 
		{
			int len = nums.size();
			if (len < 2) { return; }

			partition(nums, 1);
			partition(nums, 2);
		}
     
        void Main()
        {
			sortColors(createVector({ 1, 0 }));
        }
    }
}
