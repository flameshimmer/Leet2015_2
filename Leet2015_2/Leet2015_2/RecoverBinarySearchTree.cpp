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
		void findNode(TreeNode* node, TreeNode*& prev, TreeNode*& n1, TreeNode*& n2)
		{
			if (!node){ return; }

			findNode(node->left, prev, n1, n2);
			if (prev && prev->val > node->val)
			{
				if (!n1) { n1 = prev; }
				n2 = node;
			}
			prev = node;
			findNode(node->right, prev, n1, n2);
		}

		void recoverTree(TreeNode* root)
		{
			if (!root) { return; }
			TreeNode* n1 = NULL;
			TreeNode* n2 = NULL;
			TreeNode* prev = NULL;
			findNode(root, prev, n1, n2);
			if (n1 && n2)
			{
				int temp = n1->val;
				n1->val = n2->val;
				n2->val = temp;
			}
		}
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(3);
			TreeNode* n2 = new TreeNode(1);
			TreeNode* n3 = new TreeNode(2);

			n1->left = n2;
			n1->right = n3;
			recoverTree(n1);
        }
    }
}
