#include "stdafx.h"

//Given a collection of candidate numbers(C) and a target number(T), 
//find all unique combinations in C where the candidate numbers sums to T.
//
//Each number in C may only be used once in the combination.
//
//Note:
//All numbers(including target) will be positive integers.
//Elements in a combination(a1, a2, …, ak) must be in non - descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//The solution set must not contain duplicate combinations.
//For example, given candidate set 10, 1, 2, 7, 6, 1, 5 and target 8,
//A solution set is :
//[1, 7]
//[1, 2, 5]
//[2, 6]
//[1, 1, 6]

namespace Solution2
{
    namespace CombinationSumII
    {
		void helper(vector<int>& can, int start, int len, int target, vector<int>& result, vector<vector<int>>& results)
		{
			if (target == 0)
			{
				results.push_back(result);
				return;
			}
			if (target < 0 || start >= len) { return; }
			for (int i = start; i < len; i++)
			{
				result.push_back(can[i]);
				helper(can, i + 1, len, target - can[i], result, results);
				result.pop_back();

				while (i + 1 < len && can[i] == can[i + 1]) { i++; }
			}
		}

		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			vector<vector<int>> results;
			int len = candidates.size();
			if (len == 0) { return results; }

			sort(candidates.begin(), candidates.end());
			vector<int>result;
			helper(candidates, 0, len, target, result, results);
			return results;
		}
     
        void Main()
        {
         
        }
    }
}
