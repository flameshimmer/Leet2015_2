#include "stdafx.h"

//Given a binary tree where all the right nodes are either leaf nodes with a sibling
//(a left node that shares the same parent node) or empty, flip it upside down and 
//turn it into a tree where the original right nodes turned into left leaf nodes.
//
//Return the new root.
//
//For example :
//Given a binary tree{ 1, 2, 3, 4, 5 },
//				1
//	  		   / \
//			  2   3
//			 / \
//			4   5
//return the root of the binary tree[4, 5, 2, #, #, 3, 1].
//				4
//			   / \
//			  5   2
//			     / \
//			    3   1

namespace Solution2
{
    namespace BinaryTreeUpsideDown
    {     
		TreeNode* upsideDownBinaryTree(TreeNode* root) {
			if (!root || (!root->left && !root->right)) { return root; }
			
			TreeNode* left = upsideDownBinaryTree(root->left);
			TreeNode* right = upsideDownBinaryTree(root->right);

			root->left->right = root;
			root->left->left = right;
			root->left = NULL;
			root->right = NULL;
			return left;
		}
     
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n3 = new TreeNode(3);
			n1->left = n2;
			n2->left = n3;

			upsideDownBinaryTree(n1);
        }
    }
}
