#include "stdafx.h"

//Implement next permutation, which rearranges numbers into the 
//lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as 
//the lowest possible order(ie, sorted in ascending order).
//
//The replacement must be in - place, do not allocate extra memory.
//
//Here are some examples.Inputs are in the left - hand column and
//its corresponding outputs are in the right - hand column.
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1

namespace Solution2
{
    namespace NextPermutation
    {     
		void swap(vector<int>& nums, int start, int end)
		{
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
		}
		void reverse(vector<int>& nums, int start, int end)
		{
			while (start < end)
			{
				swap(nums, start, end);
				start++;
				end--;
			}		
		}

		void nextPermutation(vector<int>& nums) {
			int len = nums.size();
			if (len < 2) { return; }

			int cur = len - 2;
			while (cur >= 0)
			{
				if (nums[cur] < nums[cur + 1]) { break; }
				cur--;
			}
			if (cur < 0) { reverse(nums, 0, len - 1); return; }

			int cur2 = len - 1;
			while (cur2 > cur)
			{
				if (nums[cur2] > nums[cur]){ break; }
				cur2--;
			}
			swap(nums, cur, cur2);
			reverse(nums, cur + 1, len - 1);
		}
    
     
        void Main()
        {
         
        }
    }
}
