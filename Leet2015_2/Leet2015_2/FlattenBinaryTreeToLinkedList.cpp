#include "stdafx.h"

//Given a binary tree, flatten it to a linked list in - place.
//
//For example,
//Given
//
//			1
//		   / \
//		  2   5
//		 / \   \
//		3   4   6
//The flattened tree should look like :
//			1
//			 \
//			  2
//			   \
//				3
//				 \
//				  4
//				   \
//					5
//					 \
//					  6
namespace Solution2
{
    namespace FlattenBinaryTreeToLinkedList
    {
		
		TreeNode* flattenImpl(TreeNode* root)
		{
			if (!root || (!root->left && !root->right)) { return root; }
			TreeNode* leftTail = flattenImpl(root->left);
			TreeNode* rightTail = flattenImpl(root->right);
			if (leftTail && rightTail)
			{
				leftTail->right = root->right;
				root->right = root->left;
				root->left = NULL;
				return rightTail;
			}
			else if (leftTail)
			{
				root->right = root->left;
				root->left = NULL;
				return leftTail;
			}
			else
			{
				return rightTail;
			}
		}

		void flatten(TreeNode* root) 
		{			
			flattenImpl(root);			
		}
     
     
        void Main()
        {
         
        }
    }
}
