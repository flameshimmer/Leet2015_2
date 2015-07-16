#include "stdafx.h"

//Two elements of a binary search tree(BST) are swapped by mistake.
//
//Recover the tree without changing its structure.
//
//Note:
//A solution using O(n) space is pretty straight forward.Could you devise a constant space solution ?

namespace Solution2
{
    namespace RecoverBinarySearchTree
    {
		void findNodes(TreeNode* node, int min, int max, TreeNode*& t1, TreeNode*&t2)
		{
			if (!node) { return; }
			if (t1 && t2) { return; }
			if (node->val <= min || node->val >= max) 
			{
				if (!t1) { t1 = node; }
				else { t2 = node; }
			}
			findNodes(node->left, min, node->val, t1, t2);
			findNodes(node->right, node->val, max, t1, t2);
		}

		void recoverTree(TreeNode* root) 
		{
			if (!root) { return; }
			TreeNode* t1 = NULL;
			TreeNode* t2 = NULL;
			findNodes(root, INT_MIN, INT_MAX, t1, t2);
			if (!t1 || !t2) { return; }
			int temp = t1->val;
			t1->val = t2->val;
			t2->val = temp;
		}
     
        void Main()
        {
         
        }
    }
}
