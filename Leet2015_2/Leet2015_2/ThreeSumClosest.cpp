#include "stdafx.h"

//Given an array S of n integers, find three integers in S such that the sum is
//closest to a given number, target.Return the sum of the three integers.You may
//assume that each input would have exactly one solution.
//
//For example, given array S = { -1 2 1 - 4 }, and target = 1.
//
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

namespace Solution2
{
    namespace ThreeSumClosest
    {
     
		int threeSumClosest(vector<int>& nums, int target) 
		{
			int result = 0;
			int closestDiff = INT_MAX;
			int len = nums.size();
			if (len < 3) { return result; }

			sort(nums.begin(), nums.end());


			for (int i = 0; i < len-2; i++)
			{				
				int target2 = target - nums[i];
				int start = i + 1;
				int end = len - 1;
				while (start < end)
				{
					int sum = nums[start] + nums[end];
					if (sum == target2)
					{
						return target;
					}
					else if (sum < target2)
					{
						if (target2 - sum < closestDiff) { closestDiff = target2 - sum; result = nums[i] + sum; }
						start++;
						while (start + 1 < len && nums[start] == nums[start - 1]) { start++; }
					}
					else
					{
						if (sum - target2 < closestDiff) { closestDiff = sum - target2; result = nums[i] + sum; }
						end--;
						while (end >= 0 && nums[end] == nums[end + 1]) { end--; }
					}
				}
				
				while (i + 1 < len && nums[i] == nums[i + 1])
				{
					i++;
				}
			}
			return result;
		}
     
     
        void Main()
        {
			print(threeSumClosest(createVector({ 1, 1, 1, 0 }), 100));
			print(threeSumClosest(createVector({ 1, 1, -1, -1, 3 }), -1));
			print(threeSumClosest(createVector({ 0, 2, 1, -3 }), 1));
			print(threeSumClosest(createVector({ 1, 1, -1 }), 0));
        }
    }
}
