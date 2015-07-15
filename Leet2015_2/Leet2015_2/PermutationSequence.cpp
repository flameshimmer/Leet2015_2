#include "stdafx.h"

//The set[1, 2, 3, …, n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order,
//We get the following sequence(ie, for n = 3) :
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//Given n and k, return the kth permutation sequence.
//
//Note: Given n will be between 1 and 9 inclusive.

namespace Solution2
{
    namespace PermutationSequence
    {
     
		string getPermutation(int n, int k) {
			vector<int> options(n, 0);
			int permCount = 1;
			for (int i = 0; i < n; i++)
			{
				options[i] = i+1;
				permCount *= i + 1;
			}

			k--;
			string targetNum;

			for (int i = 0; i < n; i++)
			{
				permCount /= n - i;
				int index = k / permCount;
				targetNum.push_back(options[index] + '0');
				for (int i = index; i < n - 1; i++)
				{
					options[i] = options[i + 1];
				}
				k %= permCount;
			}
			return targetNum;
		}
     
        void Main()
        {
			print(getPermutation(1, 1));
        }
    }
}
