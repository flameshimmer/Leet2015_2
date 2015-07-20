#include "stdafx.h"

//Follow up for "Search in Rotated Sorted Array":
//What if duplicates are allowed ?
//
//Would this affect the run - time complexity ? How and why ?
//
//Write a function to determine if a given target is in the array.


namespace Solution2
{
    namespace SearchInRotatedSortedArrayII
    {
     
		bool search(vector<int>& nums, int target) {
			int len = nums.size();
			if (len == 0) { return false; }

			int start = 0;
			int end = len - 1;
			while (start <= end)
			{
				while (start < end && nums[start] == nums[end]) { start++; }
				int mid = start + (end - start) / 2;
				if (nums[mid] == target) { return true; }
				else if ((nums[start] <= nums[mid] && target <= nums[mid] && target >= nums[start]) || (nums[mid] <= nums[end] && (target < nums[mid] || target > nums[end])))
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return false;
		}
     
     
        void Main()
        {
			vector<int> input;

			input = createVector({ 3, 1, 1 });
			print(search(input, 3));

			input = createVector({ 1, 1, 3, 1 });
			print(search(input, 3));


			input = createVector({ 1 });
			print(search(input, 0));
         
        }
    }
}
