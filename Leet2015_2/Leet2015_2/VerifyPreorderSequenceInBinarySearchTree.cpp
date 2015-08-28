#include "stdafx.h"

//Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
//
//You may assume each number in the sequence is unique.
//
//Follow up :
//Could you do it using only constant space complexity ?

namespace Solution2
{
	namespace VerifyPreorderSequenceInBinarySearchTree
	{
		
		int findBoundary(vector<int>& preorder, int start, int end, int val)
		{
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				int midVal = preorder[mid];
				if (midVal > val)
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return end;
		}

		bool verify(vector<int>& preorder, int start, int end, int minVal, int maxVal)
		{
			if (start > end) { return true; }
			int val = preorder[start];
			if (val < minVal || val > maxVal) { return false; }
			if (start == end) { return true; }

			int boundary = findBoundary(preorder, start, end, val);
			bool leftResult = verify(preorder, start+1, boundary, minVal, val);
			bool rightResult = verify(preorder, boundary + 1, end, val, maxVal);
			return leftResult && rightResult;
		}




		bool verifyPreorder(vector<int>& preorder) {
			int len = preorder.size();
			if (len < 3) { return true; }

			return verify(preorder, 0, len - 1, INT_MIN, INT_MAX);
		}

		namespace TLE
		{
			bool verify(vector<int>& preorder, int start, int end)
			{
				if (start >= end) { return true; }
				int val = preorder[start];
				int i = start + 1;

				while (i <= end && preorder[i] < val) { i++; }
				int mid = i - 1;
				if (!verify(preorder, start + 1, mid)) { return false; }
				while (i <= end && preorder[i] > val) { i++; }
				if (i != end + 1 || !verify(preorder, mid + 1, end)) { return false; }
				return true;
			}


			bool verifyPreorder(vector<int>& preorder) {
				int len = preorder.size();
				if (len < 3) { return true; }

				return verify(preorder, 0, len - 1);
			}
		}

		void  Main()
		{
			//print(verifyPreorder(createVector({ 1, 3, 2 })));
			//print(verifyPreorder(createVector({ 2, 3, 1 })));
			//print(verifyPreorder(createVector({ 2, 1, 3 })));
			print(verifyPreorder(createVector({ 1, 2, 3 })));
		}
	}
}