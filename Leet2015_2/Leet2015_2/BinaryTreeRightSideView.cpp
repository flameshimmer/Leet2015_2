#include "stdafx.h"

//Given a binary tree, imagine yourself standing on the right side of it, 
//return the values of the nodes you can see ordered from top to bottom.
//
//For example :
//Given the following binary tree,
//		1            <-- -
//	   / \
//	  2   3         <-- -
//	  \     \
//	   5     4       <-- -
//You should return[1, 3, 4].

namespace Solution2
{
    namespace BinaryTreeRightSideView
    {     
		void getNodes(TreeNode* node, vector<int>& result, int height, int& maxHeight)
		{
			if (!node) { return; }
			if (height > maxHeight)
			{
				maxHeight = height;
				result.push_back(node->val);
			}
			getNodes(node->right, result, height + 1, maxHeight);
			getNodes(node->left, result, height + 1, maxHeight);
		}

		vector<int> rightSideView(TreeNode* root) 
		{
			vector<int> result;
			if (!root) { return result; }

			int maxHeight = 0;
			getNodes(root, result, 1, maxHeight);
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
