#include "stdafx.h"

//Find all possible combinations of k numbers that add up to a number n, 
//given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//Ensure that numbers within the set are sorted in ascending order.
//
//Example 1:
//
//Input : k = 3, n = 7
//
//Output :
//
//	   [[1, 2, 4]]
//
//		Example 2 :
//
//		Input : k = 3, n = 9
//
//			Output :
//
//				   [[1, 2, 6], [1, 3, 5], [2, 3, 4]]

namespace Solution2
{
    namespace CombinationSumIII
    {
		void helper(int k, int target, int start, int level, vector<int>& result, vector<vector<int>>& results)
		{
			if (target <= 0 || level == k)
			{
				if (level == k && target == 0)
				{
					results.push_back(result);
				}				
				return;
			}

			for (int i = start; i <= 9; i++)
			{
				result.push_back(i);
				helper(k, target - i, i + 1, level + 1, result, results);
				result.pop_back();
			}
		}

		vector<vector<int>> combinationSum3(int k, int n) 
		{
			vector<vector<int>> results;
			if (k == 0 || n == 0) { return results; }
			vector<int> result;
			helper(k, n, 1, 0, result, results);
			return results;
		}
     
     
        void Main()
        {
         
        }
    }
}
