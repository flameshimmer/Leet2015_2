#include "stdafx.h"

//Numbers can be regarded as product of its factors. For example,
//
//8 = 2 x 2 x 2;
//  = 2 x 4.
//Write a function that takes an integer n and return all possible combinations of its factors.
//
//Note: 
//Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2].
//You may assume that n is always positive.
//Factors should be greater than 1 and less than n.
//Examples: 
//input: 1
//output: 
//[]
//input: 37
//output: 
//[]
//input: 12
//output:
//[
//  [2, 6],
//  [2, 2, 3],
//  [3, 4]
//]
//input: 32
//output:
//[
//  [2, 16],
//  [2, 2, 8],
//  [2, 2, 2, 4],
//  [2, 2, 2, 2, 2],
//  [2, 4, 4],
//  [4, 8]
//]

namespace Solution2
{
	namespace FactorCombinations
	{

		vector<vector<int>> getFactors(int n, int start) {

			vector<vector<int>> result;
			if (n < 2) { return result; }

			for (int i = start; i <= sqrt(n); i++)
			{
				if (n % i == 0) 
				{
					result.push_back({ i, n / i });
					vector<vector<int>> sub = getFactors(n / i, i);
					for (auto s : sub)
					{
						s.insert(s.begin(), i);
						result.push_back(s);
					}
				}
			}
			return result;
		}

		vector<vector<int>> getFactors(int n) {
			return getFactors(n, 2);
		}

		void Main()
		{
			print(getFactors(32));
		}
	}
}
