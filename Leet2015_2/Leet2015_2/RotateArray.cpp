#include "stdafx.h"

//Rotate an array of n elements to the right by k steps.
//
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
//
//Note:
//Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

namespace Solution2
{
    namespace RotateArray
    {
		namespace Method1{
			void reverse(vector<int>& nums, int start, int end)
			{
				while (start < end)
				{
					int temp = nums[start];
					nums[start] = nums[end];
					nums[end] = temp;
					start++;
					end--;
				}
			}
			void rotate(vector<int>& nums, int k)
			{
				int len = nums.size();
				k %= len;
				if (len < 2 || k == 0) { return; }
				reverse(nums, 0, len - 1);
				reverse(nums, 0, k - 1);
				reverse(nums, k, len - 1);
			}
		}
        
		namespace Method2
		{
			void rotate(vector<int>& nums, int k)
			{
				for (int i = 0; i < k; i++)
				{
					nums.insert(nums.begin(), nums.back());
					nums.pop_back();
				}
			}
		}


		void rotate(vector<int>& nums, int k) {
			int len = nums.size();
			k %= len;
			if (len < 2 || k == 0) { return; }
			
			vector<int> temp(len);
			copy(nums.begin() + (len-k), nums.end(), temp.begin());
			copy(nums.begin(), nums.begin()+ (len - k), temp.begin() + k);
			nums = temp;
		}

		void Main()
        {
			vector<int> input = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
			rotate(input, 38);
			print(input);
        }
    }
}
