#include "stdafx.h"

//Given an array S of n integers, are there elements a, b, c, and d in S such 
//that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
//Note :
//	 Elements in a quadruplet(a, b, c, d) must be in non - descending order. (ie, a ≤ b ≤ c ≤ d)
//	 The solution set must not contain duplicate quadruplets.
//	 For example, given array S = { 1 0 - 1 0 - 2 2 }, and target = 0.
//
//	 A solution set is :
//(-1, 0, 0, 1)
//(-2, -1, 1, 2)
//(-2, 0, 0, 2)

namespace Solution2
{
    namespace FourSum
    {     
		vector<vector<int>> fourSum(vector<int>& nums, int target) {
			vector<vector<int>>results;
			int len = nums.size();
			if (len < 4) { return results; }

			sort(nums.begin(), nums.end());

			for (int i = 0; i < len - 3; i++)
			{
				int target2 = target - nums[i];
				for (int j = i+1; j < len - 2; j++)
				{
					int target3 = target2 - nums[j];
					int start = j+1;
					int end = len - 1;
					while (start < end)
					{
						int sum = nums[start] + nums[end];
						if (sum == target3)
						{
							vector<int> result;
							result.push_back(nums[i]);
							result.push_back(nums[j]);
							result.push_back(nums[start]);
							result.push_back(nums[end]);
							results.push_back(result);
							start++;
							while (start < len && nums[start] == nums[start - 1]) { start++; }
						}
						else if (sum < target3)
						{
							start++;
							while (start < len && nums[start] == nums[start - 1]){ start++; }
						}
						else
						{
							end--;
							while (end >= 0 && nums[end + 1] == nums[end]){ end--; }
						}
					}
					while (j + 1 < len && nums[j] == nums[j + 1]) { j++; }
				}
				while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
			}
			return results;
		}
		
		namespace KSum
		{
			void kSum(vector<int>& nums, vector<int>& result, int start, int k, int target, vector<vector<int>>& results)
			{
				int len = nums.size();
				if (k == 2)
				{
					int end = len - 1;
					while (start < end)
					{
						int sum = nums[start] + nums[end];
						if (sum == target)
						{
							result.push_back(nums[start]);
							result.push_back(nums[end]);
							results.push_back(result);
							result.pop_back();
							result.pop_back();
							start++;
							while (start < len && nums[start] == nums[start - 1]) { start++; }
						}
						else if (sum < target)
						{
							start++;
							while (start < len && nums[start] == nums[start - 1]) { start++; }
						}
						else
						{
							end--;
							while (end >= 0 && nums[end] == nums[end + 1]) { end--; }
						}
					}
				}
				else
				{
					for (int i = start; i < len-(k-1); i++)
					{
						result.push_back(nums[i]);
						kSum(nums, result, i + 1, k - 1, target - nums[i], results);
						result.pop_back();

						while (i+1<len && nums[i] == nums[i + 1]) { i++; }
					}
				}
			}
			
			vector<vector<int>> fourSum(vector<int>& nums, int target)
			{
				sort(nums.begin(), nums.end());
				vector<vector<int>> results;
				vector<int> result;
				kSum(nums, result, 0, 4, target, results);
				return results;
			}
		}
     
        void Main()
        {
			print(KSum::fourSum(createVector({ 1, 0, -1, 0, -2, 2 }), 0));
        }
    }
}
