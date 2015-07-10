#include "stdafx.h"

//Find the contiguous subarray within an array(containing at least one number) which has the largest product.
//
//For example, given the array[2, 3, -2, 4],
//the contiguous subarray[2, 3] has the largest product = 6.

namespace Solution2
{
    namespace MaximumProductSubarray
    {
		int maxProduct(vector<int>& nums, int start, int end)
		{
			if (start == end) { return nums[start]; }

			int result = 1;
			int firstNeg = 0;
			int lastNeg = 1;
			for (int i = 0; i < end - start + 1; i++)
			{
				result *= nums[start + i];
				if (firstNeg == 0 && result < 0) { firstNeg = result; }
				if (lastNeg > 0) { lastNeg *= nums[end - i]; }
			}
			if (result > 0) { return result; }
			return result / max(firstNeg, lastNeg);
		}

		int maxProduct(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }
			if (len == 1) { return nums[0]; }
			int start = 0;
			int result = 0;
			while (start < len)
			{
				while(start < len && nums[start] == 0) { start++; }
				int end = start + 1;
				while (end < len && nums[end] != 0) { end++; }
				end--;
				if (start < len)
				{
					result = max(result, maxProduct(nums, start, end));
				}
				start = end + 1;
			}
			return result;
		}
     
        void Main()
        {
			print(maxProduct(createVector({ -4, -3})));
			print(maxProduct(createVector({ -2, 0, -1 })));
			print(maxProduct(createVector({ 3, -2, -3, -3, 1, 3, 0 })));
        }
    }
}
