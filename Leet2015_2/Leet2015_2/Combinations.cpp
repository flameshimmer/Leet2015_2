#include "stdafx.h"

//Given two integers n and k, return all possible combinations 
//of k numbers out of 1 ... n.
//
//For example,
//If n = 4 and k = 2, a solution is :
//
//[
//	[2, 4],
//	[3, 4],
//	[2, 3],
//	[1, 2],
//	[1, 3],
//	[1, 4],
//]

namespace Solution2
{
    namespace Combinations
    {     
		void combine(int start, int level, int n, int k, vector<int>& result, vector<vector<int>>& results)
		{
			if (level == k)
			{
				results.push_back(result);
				return;
			}
			for (int i = start; i <= n; i++)
			{
				result.push_back(i);
				combine(i + 1, level + 1, n, k, result, results);
				result.pop_back();
			}
		}

		vector<vector<int>> combine(int n, int k) 
		{
			vector<vector<int>> results;
			if (k == 0) { return results; }

			vector<int> result;
			combine(1, 0, n, k, result, results);
			return results;
		}
     
        void Main()
        {
         
        }
    }
}
