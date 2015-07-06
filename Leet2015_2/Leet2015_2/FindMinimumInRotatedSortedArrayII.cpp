#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.

namespace Solution2
{
    namespace FindMinimumInRotatedSortedArrayII
    {
		int findMin(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }

			int start = 0;
			int end = len - 1;
			if (nums[start] < nums[end]) { return nums[start]; }
			while (start <= end)
			{ 
				while (start + 1 < len && nums[start] == nums[start + 1]) { start++; }
				while (end - 1 >= 0 && nums[end] == nums[end - 1]) { end--; }
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
			print(findMin(createVector({ 3, 3, 1, 3 })));
        }
    }
}
