#include "stdafx.h"

//Follow up for N - Queens problem.
//
//Now, instead outputting board configurations,
//return the total number of distinct solutions.

namespace Solution2
{
    namespace NQueensII
    {
     
		bool isValid(int i, int colMask, int diagLeftMask, int diagRightMask)
		{
			int mask = colMask | diagLeftMask | diagRightMask;
			return ((1 << i) & mask) == 0;
		}


		void solve(int n, int level, vector<string>& result, vector<vector<string>>& results, int colMask, int diagLeftMask, int diagRightMask)
		{
			if (level == n)
			{
				results.push_back(result);
				return;
			}

			result.push_back(string(n, '.'));
			int lastIndex = result.size() - 1;
			for (int i = 0; i < n; i++)
			{
				if (isValid(i, colMask, diagLeftMask, diagRightMask))
				{
					result[lastIndex][i] = 'Q';
					int mask = 1 << i;
					solve(n, level + 1, result, results, colMask | mask, (diagLeftMask | mask) << 1, (diagRightMask | mask) >> 1);
					result[lastIndex][i] = '.';
				}
			}
			result.pop_back();
		}

		int totalNQueens(int n)
		{
			vector<vector<string>> results;
			vector<string> result;
			solve(n, 0, result, results, 0, 0, 0);
			return results.size();
		}

     
     
        void Main()
        {
         
        }
    }
}
