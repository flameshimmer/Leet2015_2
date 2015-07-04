#include "stdafx.h"

//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

namespace Solution2
{
    namespace ConvertSortedArrayToBinarySearchTree
    {
     
		TreeNode* build(vector<int>& nums, int start, int end)
		{
			if (start > end) { return NULL; }
			int mid = start + (end - start) / 2;

			TreeNode* newNode = new TreeNode(nums[mid]);
			newNode->left = build(nums, start, mid - 1);
			newNode->right = build(nums, mid + 1, end);
			return newNode;
		}
		TreeNode* sortedArrayToBST(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return NULL; }
			return build(nums, 0, len - 1);
		}
     
     
        void Main()
        {
         
        }
    }
}
