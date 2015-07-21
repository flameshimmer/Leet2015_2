#include "stdafx.h"

//Given a collection of integers that might contain duplicates, S, return all possible subsets.
//
//Note:
//Elements in a subset must be in non - descending order.
//The solution set must not contain duplicate subsets.
//For example,
//If S = [1, 2, 2], a solution is :
//
//[
//	[2],
//	[1],
//	[1, 2, 2],
//	[2, 2],
//	[1, 2],
//	[]
//]

namespace Solution2
{
    namespace SubsetsII
    {
     
		void getSubSets(vector<int>& nums, int len, int start, vector<int>& result, vector<vector<int>>& results)
		{
			results.push_back(result);
			if (start == len)
			{
				return;
			}

			for (int i = start; i < len; i++)
			{
				result.push_back(nums[i]);
				getSubSets(nums, len, i + 1, result, results);
				result.pop_back();

				while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
			}
		}

		vector<vector<int>> subsetsWithDup(vector<int>& nums)
		{
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }
			vector<int> result;
			sort(nums.begin(), nums.end());
			getSubSets(nums, len, 0, result, results);
			return results;
		}
     
        void Main()
        {
         
        }
    }
}
