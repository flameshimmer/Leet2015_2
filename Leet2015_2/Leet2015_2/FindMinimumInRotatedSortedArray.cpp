#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//You may assume no duplicate exists in the array.

namespace Solution2
{
    namespace FindMinimumInRotatedSortedArray
    {
     
		int findMin(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }

			int start = 0;
			int end = len - 1;

			if (nums[start] <= nums[end]) { return nums[start]; }
			while (start < end)
			{
				int mid = start + (end - start) / 2;
				if (nums[start] < nums[mid])
				{
					start = mid;
				}
				else if (nums[mid] < nums[end])
				{
					end = mid;
				}
				else
				{
					return nums[end];
				}
			}
		}
     
        void Main()
        {
			print(findMin(createVector({ 3, 1, 2 })));
			print(findMin(createVector({ 3, 2, 1 })));
			print(findMin(createVector({ 2, 1 })));         
        }
    }
}
