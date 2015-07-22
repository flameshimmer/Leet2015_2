#include "stdafx.h"

//Given a binary tree containing digits from 0 - 9 only, 
//each root - to - leaf path could represent a number.
//
//An example is the root - to - leaf path 1->2->3 which represents the number 123.
//
//Find the total sum of all root - to - leaf numbers.
//
//For example,
//
//	  1
//   / \
//  2   3
//The root - to - leaf path 1->2 represents the number 12.
//The root - to - leaf path 1->3 represents the number 13.
//
//Return the sum = 12 + 13 = 25.

namespace Solution2
{
    namespace SumRootToLeafNumbers
    {
		void getSum(TreeNode* node, int parentVal, int& sum)
		{
			if (!node) { return; }
			int curVal = parentVal * 10 + node->val;
			if (!node->left && !node->right)
			{
				sum += curVal;
			}
			getSum(node->left, curVal, sum);
			getSum(node->right, curVal, sum);
		}

		int sumNumbers(TreeNode* root) {
			int sum = 0;
			getSum(root, 0, sum);
			return sum;
		}
     
        void Main()
        {
         
        }
    }
}
