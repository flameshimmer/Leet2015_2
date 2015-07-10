#include "stdafx.h"

//Given a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest 
//path from the root node down to the farthest leaf node.

namespace Solution2
{
    namespace MaximumDepthOfBinaryTree
    {     
		void getMaxDepth(TreeNode* node, int curDepth, int& maxDepth)
		{
			if (!node->left && !node->right)
			{
				maxDepth = max(maxDepth, curDepth);
			}
			if (node->left) { getMaxDepth(node->left, curDepth + 1, maxDepth); }
			if (node->right) { getMaxDepth(node->right, curDepth + 1, maxDepth); }
		}
		int maxDepth(TreeNode* root) {
			if (!root) { return 0; }
			int maxDepth = 0;
			getMaxDepth(root, 1, maxDepth);
			return maxDepth;
		}
     
        void Main()
        {
         
        }
    }
}
