#include "stdafx.h"


namespace Solution2
{
	namespace LowestCommonAncestorOfABinaryTree
	{

		TreeNode* lowestCommonAncestorImpl(TreeNode* root, TreeNode*& p, TreeNode*& q) {
			if (!root) { return NULL; }
			TreeNode* p2 = p;
			TreeNode* q2 = q;
			TreeNode* L = lowestCommonAncestorImpl(root->left, p, q);
			TreeNode* R = lowestCommonAncestorImpl(root->right, p2, q2);

			if (L || R) { return L ? L : R; }

			if (p2 == NULL || root == p) { p = NULL; }
			if (q2 == NULL || root == q) { q = NULL; }
			if (!p && !q) { return root; }
			return NULL;
		}

		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (!root || !p || !q) { return NULL; }
			return lowestCommonAncestorImpl(root, p, q);
		}

		namespace other
		{
			TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
				if (!root || !p || !q) { return NULL; }
				if (root == p || root == q) { return root; }

				TreeNode* L = lowestCommonAncestor(root->left, p, q);
				TreeNode* R = lowestCommonAncestor(root->right, p, q);
				if (L&&R) { return root; }
				else { return L ? L : R; }
			}
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