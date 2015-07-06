#include "stdafx.h"

//A peak element is an element that is greater than its neighbors.
//
//Given an input array where num[i] ≠ num[i + 1], find a peak element and return its index.
//
//The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
//You may imagine that num[-1] = num[n] = -∞.
//
//For example, in array[1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
//click to show spoilers.
//
//Note:
//Your solution should be in logarithmic complexity.

namespace Solution2
{
    namespace FindPeakElement
    {
		int findPeakElement(vector<int>& nums) {
			int len = nums.size();
			if (len < 0) { return 0; }

			int start = 0;
			int end = len - 1;
			while (start < end)
			{
				int mid = start + (end - start) / 2;
				int upper = mid + 1 < len ? nums[mid + 1] : INT_MIN;
				int lower = mid - 1 >= 0 ? nums[mid - 1] : INT_MIN;
				if (lower < nums[mid] && upper < nums[mid])
				{
					return mid;
				}
				else if (lower > nums[mid])
				{
					end = mid-1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return nums[start] > nums[end] ? start : end;
		}
     
        void Main()
        {
			print(findPeakElement(createVector<int>({ INT_MIN })));
			print(findPeakElement(createVector<int>({ 1, 2 })));
        }
    }
}
