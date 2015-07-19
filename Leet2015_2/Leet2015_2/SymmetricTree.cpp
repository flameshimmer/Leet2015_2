#include "stdafx.h"
//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).
//
//For example, this binary tree is symmetric :
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//
//But the following is not :
//    1
//   / \
//  2   2
//   \   \
//   3    3
//Note:
//Bonus points if you could solve it both recursively and iteratively.
namespace Solution2
{
    namespace SymmetricTree
    {
     
		bool isSymmetric(TreeNode* a, TreeNode* b)
		{
			if (!a && !b) { return true; }
			if (!a || !b || a->val != b->val) { return false; }
			return isSymmetric(a->left, b->right) && isSymmetric(a->right, b->left);
		}

		bool isSymmetric(TreeNode* root) {
			if (!root) { return true; }
			return isSymmetric(root->left, root->right);
		}
     
     
        void Main()
        {
         
        }
    }
}
