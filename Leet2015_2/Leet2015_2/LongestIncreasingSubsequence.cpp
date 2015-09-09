#include "stdafx.h"
//Given a sequence of integers, find the longest increasing subsequence(LIS).
//
//You code should return the length of the LIS.
//
//Example
//For[5, 4, 1, 2, 3], the LIS  is[1, 2, 3], return 3
//
//For[4, 2, 4, 5, 3, 7], the LIS is[4, 4, 5, 7], return 4
//
//Challenge
//Time complexity O(n ^ 2) or O(nlogn)
//
//Clarification
//What's the definition of longest increasing subsequence?
//
//* The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's 
//elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  
//
//* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

namespace Solution2
{
	namespace LongestIncreasingSubsequence
	{

		/**
		* @param nums: The integer array
		* @return: The length of LIS (longest increasing subsequence)
		*/
		int longestIncreasingSubsequence(vector<int> A) {
			int len = A.size();
			if (len < 2) { return len; }

			vector<int> M(len + 1, 0);
			M[1] = 1;
			int result = 1;
			for (int i = 2; i<len + 1; i++)
			{
				for (int j = 0; j<i; j++)
				{
					if (A[j - 1] <= A[i - 1]) { M[i] = max(M[i], M[j] + 1); result = max(result, M[i]); }
				}
			}
			return result;
		}

		namespace nLogn
		{
			void insert(vector<int>& Lis, int v)
			{
				int start = 0;
				int end = Lis.size() - 1;
				while (start <= end)
				{
					int mid = start + (end - start) / 2;
					if (Lis[mid] <= v)
					{
						start = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}

				if (start == Lis.size()) { Lis.push_back(v); }
				else { Lis[start] = v; }
			}

			/**
			* @param nums: The integer array
			* @return: The length of LIS (longest increasing subsequence)
			*/
			int longestIncreasingSubsequence(vector<int> A) {
				int len = A.size();
				if (len < 2) { return len; }

				vector<int> Lis;
				for (int v : A)
				{
					insert(Lis, v);
				}
				return Lis.size();
			}
		}
		void Main()
		{
		}
	}
}
