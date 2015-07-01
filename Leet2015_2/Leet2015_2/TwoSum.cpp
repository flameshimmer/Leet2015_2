#include "stdafx.h"

//Given an array of integers, find two numbers such that they add up to a specific target number.
//
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2.Please note that your returned answers(both index1 and index2) are not zero - based.
//
//You may assume that each input would have exactly one solution.
//
//Input: numbers = { 2, 7, 11, 15 }, target = 9
//   Output : index1 = 1, index2 = 2

namespace Solution2
{
    namespace TwoSum
    {
     
		vector<int> twoSum(vector<int>& nums, int target) 
		{
			vector<int> result;
			int len = nums.size();
			if (len < 2) { return result; }

			vector<pair<int, int>> input;
			for (int i = 0; i < len; i++)
			{
				input.push_back(make_pair(nums[i], i+1));
			}

			sort(input.begin(), input.end());

			int start = 0;
			int end = len - 1;
			while (start < end)
			{
				int sum = input[end].first + input[start].first;
				if (sum == target)
				{
					result.push_back(input[start].second);
					result.push_back(input[end].second);
					sort(result.begin(), result.end());
					break;
				}
				else if (sum < target)
				{
					start++;
				}
				else
				{
					end--;
				}
			}
			return result;
		}
     
     
        void Main()
        {
			print(twoSum(createVector({ 3, 2, 4 }), 6));
        }
    }
}
