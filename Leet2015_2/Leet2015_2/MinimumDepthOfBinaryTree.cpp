#include "stdafx.h"

//Given a binary tree, find its minimum depth.
//
//The minimum depth is the number of nodes along the shortest 
//path from the root node down to the nearest leaf node.

namespace Solution2
{
    namespace MinimumDepthOfBinaryTree
    {     
	
		void getMinDepth(TreeNode* root, int curDepth, int& minDepth)
		{
			if (!root->left && !root->right)
			{
				minDepth = min(minDepth, curDepth);
			}
			if (root->left) { getMinDepth(root->left, curDepth + 1, minDepth); }
			if (root->right) { getMinDepth(root->right, curDepth + 1, minDepth); }
		}
		
		int minDepth(TreeNode* root) {
			if (!root) { return 0; }
			int minDepth = INT_MAX;
			getMinDepth(root, 1, minDepth);
			return minDepth;
		}
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			print(minDepth(n1));
        }
    }
}
