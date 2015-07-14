#include "stdafx.h"

//Given a binary tree and a sum, determine if the tree has a root 
//- to - leaf path such that adding up all the values along the path equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//	      5
//	     / \
//	    4   8
//	   /   / \
//   11   13  4
//   /\        \
//  7  2        1
//return true, as there exist a root - to - leaf path 5->4->11->2 which sum is 22.

namespace Solution2
{
    namespace PathSum
    {
     
		bool hasPathSumImpl(TreeNode* node, int sum)
		{
			if (!node->left && !node->right) { return sum == node->val; }
			bool left = (node->left && hasPathSumImpl(node->left, sum - node->val));
			bool right = (node->right && hasPathSumImpl(node->right, sum - node->val));
			return left || right;
		}

		bool hasPathSum(TreeNode* root, int sum) 
		{
			if (!root) { return false; }
			return hasPathSumImpl(root, sum);
		}
     
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(-2);
			TreeNode* n2 = new TreeNode(-3);
			n1->right = n2;
			print(hasPathSum(n1, -3));
        }
    }
}
