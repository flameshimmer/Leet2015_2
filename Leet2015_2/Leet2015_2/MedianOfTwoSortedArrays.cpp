#include "stdafx.h"

//There are two sorted arrays A and B of size m and n respectively.
//Find the median of the two sorted arrays.The overall run time complexity should be O(log(m + n)).
 
namespace Solution2
{
    namespace MedianOfTwoSortedArrays
    {     
		namespace tooSlow
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
						if (c == i1) { result += curVal; }
						if (c == i2) { result += curVal; break; }
						c++;
						index++;
					}
				}

				result /= 2.0;
				return result;
			}
		}


		double findMedian(vector<int>& nums, int start, int end, int& medianIndexL, int& medianIndexR)
		{
			int len = end - start + 1;
			medianIndexL = start + (len - 1) / 2;
			medianIndexR = start + len / 2;
			double m = (double)(nums[medianIndexL] + nums[medianIndexR]) / (double)2.0;
			return m;
		}

		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
		{
			int len1 = nums1.size();
			int len2 = nums2.size();
			if (len1 == 0 && len2 == 0) { return 0; }
			int medianIndex1L = -1;
			int medianIndex1R = -1;
			int medianIndex2L = -1;
			int medianIndex2R = -1;
			if (len1 == 0 || len2 == 0) { return len2 == 0 ? findMedian(nums1, 0, len1 - 1, medianIndex1L, medianIndex1R) : findMedian(nums2, 0, len2 - 1, medianIndex2L, medianIndex2R); }

			int start1 = 0;
			int end1 = len1 - 1;
			int start2 = 0;
			int end2 = len2 - 1;
			double m1;
			double m2;
			do
			{
				m1 = findMedian(nums1, start1, end1, medianIndex1L, medianIndex1R);
				m2 = findMedian(nums2, start2, end2, medianIndex2L, medianIndex2R);

				if (m1 == m2) { return m1; }
				else if (m1 < m2)
				{
					start1 = medianIndex1R+1;
					end2 = medianIndex2L-1;
				}
				else
				{
					start2 = medianIndex2R+1;
					end1 = medianIndex1L-1;
				}
			} while (start1 <= end1 && start2 <= end2);

			double m;
			if (start1 > end1 && start2 > end2)
			{
				if (nums1[len1 - 1] <= nums2[0])
				{
					m = (double)(nums1[len1 - 1] + nums2[0]) / 2.0;
				}
				else
				{
					m = (double)(nums1[0] + nums2[len2-1]) / 2.0;
				}
			}
			else if (start1 > end1)
			{
				m = findMedian(nums2, start2, end2, medianIndex2L, medianIndex2R);
			}
			else 
			{ 
				m = findMedian(nums1, start1, end1, medianIndex1L, medianIndex1R); 
			}		
			return m;
		}

        void Main()
        {
			print(findMedianSortedArrays(createVector({ 1, 2 }), createVector({ 1, 2, 3 })));
			print(findMedianSortedArrays(createVector({ 1, 2, 3 }), createVector({ 4, 5, 6 })));
			print(findMedianSortedArrays(createVector({ 2 }), vector<int>()));
			print(findMedianSortedArrays(createVector({ 1, 1 }), createVector({ 1, 2 })));
			
			print(findMedianSortedArrays(createVector({ 1, 2 }), createVector({ 1, 2 })));
			print(findMedianSortedArrays(createVector({ 1, 1 }),createVector({ 1, 1 })));
			print(findMedianSortedArrays(vector<int>(), createVector({ 2, 3 })));
        }
    }
}
