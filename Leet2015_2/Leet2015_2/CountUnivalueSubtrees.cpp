#include "stdafx.h"

//Given a binary tree, count the number of uni-value subtrees.
//
//A Uni-value subtree means all nodes of the subtree have the same value.
//
//For example:
//Given binary tree,
//              5
//             / \
//            1   5
//           / \   \
//          5   5   5
//return 4.

namespace Solution2
{
	namespace CountUnivalueSubtrees
	{

		bool impl(TreeNode* root, int& count)
		{
			if (!root) { return true; }
			bool left = impl(root->left, count);
			bool right = impl(root->right, count);

			if (left && right
				&& (!root->left || root->left->val == root->val)
				&& (!root->right || root->right->val == root->val))
			{
				count++;
				return true;
			}
			return false;
		}


		int countUnivalSubtrees(TreeNode* root, int& val) {
			int result = 0;
			impl(root, result);
			return result;
		}

		void Main()
		{
		}
	}
}
