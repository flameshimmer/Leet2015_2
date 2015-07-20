#include "stdafx.h"

//Given a sorted array of integers, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return[-1, -1].
//
//For example,
//Given[5, 7, 7, 8, 8, 10] and target value 8,
//return[3, 4].


namespace Solution2
{
    namespace SearchForARange
    {

		int findLeftIndex(vector<int>& nums, int target)
		{
			int start = 0;
			int end = nums.size() - 1;

			while (start < end)
			{
				int mid = start + (end - start) / 2;
				if (nums[mid] < target)
				{
					start = mid + 1;
				}
				else
				{
					end = mid;
				}
			}
			if (start == end && nums[start] == target) { return start; }
			return -1;
		}

		int findRightIndex(vector<int>& nums, int target)
		{
			int start = 0;
			int end = nums.size() - 1;

			while (start < end)
			{
				int mid = start + (end - start + 1) / 2;
				if (nums[mid] > target)
				{
					end = mid - 1;
				}
				else
				{
					start = mid;
				}
			}
			if (start == end && nums[start] == target) { return start; }
			return -1;
		}

		vector<int> searchRange(vector<int>& nums, int target) {
			vector<int> result(2, -1);
			int len = nums.size();
			if (len == 0) { return result; }

			result[0] = findLeftIndex(nums, target);
			result[1] = findRightIndex(nums, target);
			return result;
		}
     
        void Main()
        {
			print(searchRange(createVector({ 5, 7, 7, 8, 8, 10 }), 8));
        }
    }
}
