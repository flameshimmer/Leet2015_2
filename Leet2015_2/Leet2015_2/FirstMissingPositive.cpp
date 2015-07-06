#include "stdafx.h"

//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//Given[1, 2, 0] return 3,
//and[3, 4, -1, 1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

namespace Solution2
{
    namespace FirstMissingPositive
    {
     
		int firstMissingPositive(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 1; }

			for (int i = 0; i < len; i++)
			{
				if (nums[i] <= 0 || nums[i] == i + 1) { continue; }

				int cur = nums[i];
				while (cur-1 >= 0 && cur-1 <len && nums[cur - 1] != cur)
				{
					int temp = nums[cur - 1];
					nums[cur - 1] = cur;
					cur = temp;
				}
			}

			for (int i = 0; i < len; i++)
			{
				if (nums[i] != i + 1) { return i+1; }
			}
			return len + 1;
		}

     
     
        void Main()
        {
			print(firstMissingPositive(createVector({ 0, -1, 3, 1 })));
        }
    }
}
