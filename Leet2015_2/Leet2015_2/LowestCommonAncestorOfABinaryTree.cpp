#include "stdafx.h"


namespace Solution2
{
	namespace LowestCommonAncestorOfABinaryTree
	{

		TreeNode* getAncestor(TreeNode* node, TreeNode*&p, TreeNode*& q)
		{
			if (!node) { return NULL; }
			
			TreeNode* p2 = p;
			TreeNode* q2 = q;
			
			TreeNode* l = getAncestor(node->left, p, q);
			TreeNode* r = getAncestor(node->right, p2, q2);
			if (l || r) { return l ? l : r; }

			if (!p2) { p = NULL; }
			if (!q2) { q = NULL; }
			if (!p && !q) { return node; }
			if (!p && node == q) { return node; }
			if (!q && node == p) { return node; }

			if (node == p) { p = NULL; }
			if (node == q) { q = NULL; }
			return NULL;			
		}


		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
		{
			if (!root || !p || !q) { return NULL; }
			return getAncestor(root, p, q);
		}

		void Main()
		{
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n3 = new TreeNode(3);
			n1->left = n2;
			n1->right = n3;
			TreeNode* result = lowestCommonAncestor(n1, n2, n3);
		}
	}
}