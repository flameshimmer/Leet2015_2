#include "stdafx.h"
//Give you an integer array(index from 0 to n - 1, where n is the size of this array)，find the longest increasing continuous 
//subsequence in this array. 
//
//(The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
//
//Example
//For[5, 4, 2, 1, 3], the LICS is[5, 4, 2, 1], return 4.
//
//For[5, 1, 2, 3, 4], the LICS is[1, 2, 3, 4], return 4.
//
//Note
//O(n) time and O(1) extra space.

namespace Solution2
{
	namespace LongestIncreasingContinuousSubsequence
	{
		/**
		* @param A an array of Integer
		* @return  an integer
		*/
		int longestIncreasingContinuousSubsequence(vector<int>& A) {
			int len = A.size();
			if (len < 2) { return len; }

			int lis = 1;
			int lds = 1;
			int result = 1;
			for (int i = 1; i<len; i++)
			{
				if (A[i] > A[i - 1])
				{
					lis++;
					result = max(result, lis);
					lds = 1;
				}
				else if (A[i] < A[i - 1])
				{
					lds++;
					result = max(result, lds);
					lis = 1;
				}
				else
				{
					lis = 1;
					lds = 1;
				}
			}
			return result;
		}

		void Main()
		{
		}
	}
}
