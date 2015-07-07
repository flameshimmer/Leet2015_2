#include "stdafx.h"

//Find the kth largest element in an unsorted array.
//Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
//For example,
//Given[3, 2, 1, 5, 6, 4] and k = 2, return 5.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ array's length.

namespace Solution2
{
    namespace KthLargestElementInAnArray
    {
		void swap(vector<int>& nums, int a, int b)
		{
			int temp = nums[a];
			nums[a] = nums[b];
			nums[b] = temp;
		}
		int partition(vector<int>& nums, int start, int end, int pivot)
		{
			int pivotVal = nums[pivot + start];
			swap(nums, start+pivot, end);

			int copy = start;
			for (int i = start; i <= end; i++)
			{
				if (nums[i] < pivotVal)
				{
					swap(nums, copy, i);
					copy++;
				}
			}
			swap(nums, copy, end);

			if (copy-start == pivot) { return nums[copy]; }
			else if (copy-start < pivot)
			{
				return partition(nums, copy + 1, end, pivot - (copy - start + 1));
			}
			else
			{
				return partition(nums, start, copy-1, pivot);
			}
		}

		int findKthLargest(vector<int>& nums, int k) 
		{
			int len = nums.size();
			if (len < k) { return -1; }
			return partition(nums, 0, len - 1, len-k);
		}
     
        void Main()
        {
			print(findKthLargest(createVector({ 2, 1 }), 1));
			print(findKthLargest(createVector({ 7, 6, 5, 4, 3, 2, 1 }), 5));
			print(findKthLargest(createVector({ 99, 99 }), 1));
			print(findKthLargest(createVector({ 1 }), 1));
			print(findKthLargest(createVector({ -1, -1 }), 2));
			
        }
    }
}
