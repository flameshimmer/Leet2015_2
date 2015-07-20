#include "stdafx.h"

//Given an array of n integers where n > 1, nums, return an array output such that output[i]
//is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given[1, 2, 3, 4], return[24, 12, 8, 6].
//
//Follow up :
//Could you solve it with constant space complexity ? (Note : The output array does not count
//	as extra space for the purpose of space complexity analysis.)

namespace Solution2
{
	namespace ProductOfArrayExceptSelf
	{
		vector<int> productExceptSelf(vector<int>& nums) 
		{
			int len = nums.size(); 
			if (len == 0) { return vector<int>(); }

			vector<int> left(len, 1);
			vector<int> right(len, 1);
			vector<int> result(len);

			for (int i = 1; i < len; i++)
			{
				left[i] = left[i - 1] * nums[i - 1];
				right[len - 1 - i] = right[len - i] * nums[len - i];
			}
			
			for (int i = 0; i < len; i++)
			{
				result[i] = left[i] * right[i];
			}
			return result;
		}

		namespace followUp
		{
			vector<int> productExceptSelf(vector<int>& nums)
			{
				int len = nums.size();
				if (len == 0) { return vector<int>(); }

				vector<int> result(len, 1);

				for (int i = 1; i < len; i++)
				{
					result[i] = result[i - 1] * nums[i - 1];
				}

				int lastNum = 1;
				for (int i = len - 2; i >= 0; i--)
				{
					result[i] *= lastNum * nums[i + 1];
					lastNum *= nums[i + 1];
				}
				return result;
			}

		}

		void Main()
		{
			print(followUp::productExceptSelf(createVector({ 9, 0, -2 })));
		}
	}
}