#include "stdafx.h"

//Invert a binary tree.
//
//					     4
//					   /   \
//					  2     7
//					 / \   / \
//					1   3 6   9
//to
//		  				4
//					  /   \
//					 7     2
//					/ \   / \
//				   9   6 3   1

namespace Solution2
{
    namespace InvertBinaryTree
    {
     
		TreeNode* invertTree(TreeNode* root) 
		{
			if (!root || (!root->left && !root->right)) { return root; }

			stack<TreeNode*> s;
			s.push(root);
			while (!s.empty())
			{
				TreeNode* cur = s.top();
				s.pop();
				TreeNode* leftChild = cur->left;
				TreeNode* rightChild = cur->right;
				if (leftChild) { s.push(leftChild); }
				if (rightChild) { s.push(rightChild); }
				cur->left = rightChild;
				cur->right = leftChild;
			}
			return root;
		}
     
        void Main()
        {
         
        }
    }
}
