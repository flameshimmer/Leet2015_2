#include "stdafx.h"
using namespace std;

//Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
//	For example, given nums = [-2, 0, 1, 3], and target = 2.
//
//	Return 2. Because there are two triplets which sums are less than 2:
//
//[-2, 0, 1]
//[-2, 0, 3]
//Follow up :
//Could you solve it in O(n2) runtime ?

namespace Solution2
{
	namespace ThreeSumSmaller
	{
		int threeSumSmaller(vector<int>& nums, int target) {
			int len = nums.size();
			if (len < 3) { return 0; }
			sort(nums.begin(), nums.end());

			int result = 0;
			for (int i = 0; i<len; i++)
			{
				int target2 = target - nums[i];
				int start = i + 1;
				int end = len - 1;
				while (start < end)
				{
					int sum = nums[start] + nums[end];
					if (sum < target2)
					{
						result += end - start;
						start++;
					}
					else
					{
						end--;
					}
				}
			}
			return result;
		}

		void Main()
		{
			print(threeSumSmaller(createVector({ 2, 0, 0, 2, -2 }), 2));
			//print(threeSumSmaller(createVector({ 3, 1, 0, -2 }), 4));
			//print(threeSumSmaller(createVector({ -1, 1, -1, -1 }), -1));
		}
	}
}
