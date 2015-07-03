#include "stdafx.h"

//Given a binary tree, determine if it is height - balanced.
//
//For this problem, a height - balanced binary tree is defined as a 
//binary tree in which the depth of the two subtrees of every node 
//never differ by more than 1.

namespace Solution2
{
    namespace BalancedBinaryTree
    {
		void getHeight(TreeNode* root, int curHeight, int& height)
		{
			if (!root) { return; }
			if (curHeight > height) { height = curHeight; }
			getHeight(root->left, curHeight + 1, height);
			getHeight(root->right, curHeight + 1, height);
		}

		bool isBalanced(TreeNode* root) {
			if (!root) { return true; }
			int lh = 0;
			int rh = 0;
			getHeight(root->left, 1, lh);
			getHeight(root->right, 1, rh);
			return (lh - rh < 2 && lh - rh > -2 && isBalanced(root->left) && isBalanced(root->right));
		}
     
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n3 = new TreeNode(3);

			n1->right = n2;
			n2->right = n3;

			print(isBalanced(n1));

			//TreeNode* n1 = new TreeNode(1);
			//TreeNode* n2 = new TreeNode(2);
			//TreeNode* n3 = new TreeNode(2);
			//TreeNode* n4 = new TreeNode(3);
			//TreeNode* n5 = new TreeNode(3);
			//TreeNode* n6 = new TreeNode(4);
			//TreeNode* n7 = new TreeNode(4);
			//
			//n1->left = n2;
			//n1->right = n3;
			//n2->left = n4;
			//n2->right = n5;
			//n4->left = n6;
			//n4->right = n7;

			//print(isBalanced(n1));
        }
    }
}
