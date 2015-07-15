#include "stdafx.h"

//Given a collection of numbers that might contain duplicates,
//return all possible unique permutations.
//
//For example,
//[1, 1, 2] have the following unique permutations :
//[1, 1, 2], [1, 2, 1], and[2, 1, 1].

namespace Solution2
{
    namespace PermutationII
    {
     
		void permuteUniqueImpl(vector<int>& nums, int len, int level, vector<bool>& can, vector<int>& result, vector<vector<int>>& results)
		{
			if (nums.size() == level)
			{
				results.push_back(result);
				return;
			}

			for (int i = 0; i < len; i++)
			{
				if (can[i])
				{
					can[i] = false;
					result.push_back(nums[i]);
					permuteUniqueImpl(nums, len, level + 1, can, result, results);
					result.pop_back();
					can[i] = true;
					while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
				}				
			}
		}

		vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }

			vector<int> result;
			vector<bool> can(len, true);
			sort(nums.begin(), nums.end());

			permuteUniqueImpl(nums, len, 0, can, result, results);
			return results;
		}     
     
        void Main()
        {
			vector<int> input = createVector({ 1, 1 });
			print(permuteUnique(input));
        }
    }
}
