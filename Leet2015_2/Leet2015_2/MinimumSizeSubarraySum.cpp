#include "stdafx.h"

//Given an array of n positive integers and a positive integer s, 
//find the minimal length of a subarray of which the sum ≥ s.If there isn't one, return 0 instead.
//
//For example, given the array[2, 3, 1, 2, 4, 3] and s = 7,
//the subarray[4, 3] has the minimal length under the problem constraint.
//
//click to show more practice.
//
//More practice :
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).


namespace Solution2
{
    namespace MinimumSizeSubarraySum
    {     
		int minSubArrayLen(int s, vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }

			int minLen = INT_MAX;
			int sum = 0;
			int start = 0;
			int end = 0;
			while (end < len)
			{
				while (end < len)
				{
					sum += nums[end];
					end++;
					if (sum >= s) { break; }
				}
				while (start <= end && sum - nums[start] >=s )
				{
					sum -= nums[start];
					start++;
				}
				if (sum >= s)
				{
					minLen = min(minLen, end - start);
				}
			}
			return minLen == INT_MAX ? 0 : minLen;
		}
     
		namespace logn
		{
			vector<int> accumulate(vector<int>& nums)
			{
				int len = nums.size();
				vector<int> sum(len + 1, 0);
				for (int i = 1; i < len + 1; i++)
				{
					sum[i] = sum[i - 1] + nums[i - 1];
				}
				return sum;
			}

			int upper_bound(vector<int>& nums, int start, int end, int target)
			{
				while (start < end)
				{
					int mid = start + (end - start) / 2;
					if (nums[mid] <= target)
					{
						start = mid + 1;
					}
					else
					{
						end = mid;
					}
				}
				if (nums[end] > target) { return end; }
				if (nums[start] > target) { return start; }
				return -1;
			}

			int minSubArrayLen(int s, vector<int>& nums)
			{
				vector<int> sum = accumulate(nums);
				int minLen = INT_MAX;
				for (int i = 1; i < sum.size(); i++)
				{
					if (sum[i] >= s)
					{
						int p = upper_bound(sum, 0, i, sum[i] - s);
						if (p != -1) { minLen = min(minLen, i - p + 1); }
					}
				}
				return minLen == INT_MAX ? 0 : minLen;
			}
		}

        void Main()
        {
			print(logn::minSubArrayLen(5, createVector({ 2, 3, 1, 1, 1, 1, 1 })));
			print(logn::minSubArrayLen(7, createVector({ 2, 3, 1, 2, 4, 3 })));
			print(logn::minSubArrayLen(3, createVector({ 1, 1 })));
        }
    }
}
