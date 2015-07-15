#include "stdafx.h"

//Given a collection of numbers, return all possible permutations.
//
//For example,
//[1, 2, 3] have the following permutations :
//[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and[3, 2, 1].

namespace Solution2
{
    namespace Permutations
    {
     
		void permute(vector<int>& nums, int len, int level, vector<bool>& can, vector<int>&result, vector<vector<int>>& results)
		{
			if (level == len)
			{
				results.push_back(result);
				return;
			}

			for (int i = 0; i < len; i++)
			{
				if (can[i])
				{
					result.push_back(nums[i]);
					can[i] = false;
					permute(nums, len, level + 1, can, result, results);
					can[i] = true;
					result.pop_back();
				}
			}

		}

		vector<vector<int>> permute(vector<int>& nums) 
		{
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }

			vector<int> result;
			vector<bool>can(len, true);
			permute(nums, len, 0, can, result, results);
			return results;
		}
     
        void Main()
        {
         
        }
    }
}
