#include "stdafx.h"

//Given an integer array of size n, find all elements that appear more than ⌊ n / 3 ⌋ times.The algorithm should run in linear time and in O(1) space.

namespace Solution2
{
	namespace MajorityElementII
	{

		vector<int> majorityElement(vector<int>& nums) {
			vector<int> result;
			int len = nums.size();
			if (len == 0) { return result; }

			int c1 = 0, v1 = 0, c2 = 0, v2 = 0;
			for (int val : nums)
			{
				if (val == v1) { c1++; }
				else if (val == v2) { c2++; }
				else
				{
					if (c1 && c2) { c1--; c2--; }
					else if (c1 == 0) { c1 = 1; v1 = val; }
					else { c2 = 1; v2 = val; }
				}
			}

			c1 = 0; c2 = 0;
			for (int val : nums)
			{
				if (val == v1) { c1++; }
				else if (val == v2) { c2++; }
			}
			if (c1 > len / 3) { result.push_back(v1); }
			if (c2 > len / 3) { result.push_back(v2); }
			return result;
		}

		void Main()
		{
			vector<int> input;

			input = { 1, 1, 1, 2, 3, 4, 5, 6};
			print(majorityElement(input));

			input = { 0, -1, 2, -1 };
			print(majorityElement(input));

			input = { 6, 6, 6, 7, 7 };
			print(majorityElement(input));

			input = { 2, 2, 1, 3 };
			print(majorityElement(input));

			input = { 1, 2, 3 };
			print(majorityElement(input));
		}
	}
}