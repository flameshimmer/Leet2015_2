#include "stdafx.h"

//Given a binary tree, find the maximum path sum.
//
//The path may start and end at any node in the tree.
//
//For example :
//Given the below binary tree,
//
//		 1
//		/ \
//	   2   3
//Return 6.

namespace Solution2
{
    namespace BinaryTreeMaximumPathSum
    {
		int getMax(TreeNode* node, int& maxAcrossRoot)
		{
			if (!node) { return 0; }
			int left = getMax(node->left, maxAcrossRoot);
			int right = getMax(node->right, maxAcrossRoot);
			int cMax = node->val;
			if (left > 0) { cMax += left; }
			if (right > 0) { cMax += right; }

			maxAcrossRoot = max(maxAcrossRoot, cMax);
			return max(node->val, node->val + max(left, right));
		}


		int maxPathSum(TreeNode* root) 
		{
			int maxAcrossRoot = INT_MIN;
			int maxEndByRoot = getMax(root, maxAcrossRoot);
			return max(maxAcrossRoot, maxEndByRoot);
		}
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n3 = new TreeNode(3);
			n1->left = n2;
			n1->right = n3;
			print(maxPathSum(n1));         
        }
    }
}
