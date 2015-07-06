#include "stdafx.h"

//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Note:
//You may assume that A has enough space(size that is greater or equal to m + n) to hold 
//additional elements from B.The number of elements initialized in A and B are m and n respectively.


namespace Solution2
{
    namespace MergeSortedArray
    {
     
		void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
		{
			if (n == 0) { return; }
			int i1 = m - 1;
			int i2 = n - 1;
			int i = m + n - 1;

			while (i1 >= 0 && i2 >= 0)
			{
				nums1[i] = nums2[i2] > nums1[i1] ? nums2[i2] : nums1[i1];
				if (nums1[i] == nums2[i2]) { i2--; }
				else { i1--; }
				i--;
			}
			while (i2 >= 0)
			{
				nums1[i] = nums2[i2];
				i2--;
				i--;
			}
		}
          
        void Main()
        {
         
        }
    }
}
