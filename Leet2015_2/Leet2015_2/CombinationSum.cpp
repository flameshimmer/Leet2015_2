#include "stdafx.h"

//Given a set of candidate numbers(C) and a target number(T), 
//find all unique combinations in C where the candidate numbers sums to T.
//
//The same repeated number may be chosen from C unlimited number of times.
//
//Note:
//All numbers(including target) will be positive integers.
//Elements in a combination(a1, a2, …, ak) must be in 
//non - descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//
//For example, given candidate set 2, 3, 6, 7 and target 7,
//
//A solution set is :
//[7]
//[2, 2, 3]

namespace Solution2
{
    namespace CombinationSum
    {
		void helper(vector<int>& can, int len , int target, int start, vector<int>& result, vector<vector<int>>& results)
		{
			if (target == 0)
			{
				results.push_back(result);
				return;
			}
			if (target < 0 || start == len) { return; }

			for (int i = start; i < len; i++)
			{
				result.push_back(can[i]);
				helper(can, len, target - can[i], i, result, results);
				result.pop_back();
			}
		}


		vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
		{
			vector<vector<int>> results;
			int len = candidates.size();
			if (len == 0) { return results; }
			sort(candidates.begin(), candidates.end());
			vector<int> result;
			helper(candidates, len, target, 0, result, results);
			return results;
		}
     
     
        void Main()
        {
			print(combinationSum(createVector({1}), 1));
        }
    }
}
