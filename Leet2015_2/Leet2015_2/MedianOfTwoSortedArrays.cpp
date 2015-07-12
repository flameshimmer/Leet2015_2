#include "stdafx.h"

//There are two sorted arrays A and B of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
 
namespace Solution2
{
    namespace MedianOfTwoSortedArrays
    {
     

		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
		{
			int len1 = nums1.size();
			int len2 = nums2.size();
			int len = len1 + len2;
			if (len == 0) { return 0; }

			int i1 = -1;
			int i2 = -1;
			int found = 0;
			if (len % 2 == 1) { i1 = len / 2; i2 = i1; }
			else { i1 = len / 2 - 1; i2 = len / 2; }

			int c1 = 0;
			int c2 = 0;
			int c = 0;
			double result = 0;
			while (c1 < len1 && c2 < len2)
			{
				int curVal;
				if (nums1[c1] < nums2[c2]) { curVal = nums1[c1]; c1++; }
				else { curVal = nums2[c2]; c2++; }
				if (c == i1) { result += curVal; found++; }
				if (c == i2) { result += curVal; found++; break; }
				c++;
			}

			if (found < 2)
			{
				vector<int>& nums = (c1 == len1) ? nums2 : nums1;
				int len = (c1 == len1) ? len2 : len1;
				int index = (c1 == len1) ? c2 : c1;				
				while (index < len)
				{
					int curVal = nums[index];
					if (c == i1) { result += curVal;}
					if (c == i2) { result += curVal; break; }
					c++;
					index++;
				}				
			}

			result /= 2.0;
			return result;
		}
     
        void Main()
        {
			print(findMedianSortedArrays(createVector({ 1, 2 }), createVector({ 1, 2 })));
			print(findMedianSortedArrays(createVector({ 1, 1 }),createVector({ 1, 1 })));
			print(findMedianSortedArrays(vector<int>(), createVector({ 2, 3 })));
        }
    }
}
