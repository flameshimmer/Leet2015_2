#include "stdafx.h"


//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search.If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.



namespace Solution2
{
    namespace SearchInRotatedSortedArray
    {     
		int search(vector<int>& nums, int target) {
			int len = nums.size();
			if (len == 0) { return -1; }

			int start = 0;
			int end = len - 1;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (target == nums[mid]) 
				{ 
					return mid; 
				}
				else if ((nums[start] < nums[mid] && target <= nums[mid] && target >= nums[start]) || (nums[mid] < nums[end] && (target < nums[mid] || target > nums[end])))
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return -1;
		}
     
        void Main()
        {
			vector<int> input;

			input = createVector({ 1});
			print(search(input, 2));
			
			input = createVector({ 1, 3 });
			print(search(input, 3));

			input = createVector({ 5, 1, 3 });
			print(search(input, 5));

			input = createVector({ 3, 5, 1 });
			print(search(input, 3));

			
        }
    }
}
