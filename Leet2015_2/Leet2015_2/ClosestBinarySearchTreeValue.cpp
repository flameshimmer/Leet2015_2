#include "stdafx.h"


//Given a non - empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.
//

namespace Solution2
{
	namespace ClosestBinarySearchTreeValue
	{
		int closestValue(TreeNode* root, double target) {
			TreeNode* cur = root;
			int result = root->val;

			while (cur)
			{
				if (cur->val == target) { return cur->val; }
				else if (abs(cur->val - target) < abs(result - target)) { result = cur->val; }
				if (cur->val < target) { cur = cur->right; }
				else { cur = cur->left; }
			}
			return result;
		}


		namespace recursive
		{
			void getResult(TreeNode* node, double target, double& result)
			{
				if (!node) { return; }
				if (abs((double)node->val - target) < abs(result - target)) {result = (double)node->val; }

				if ((double)node->val < target) { getResult(node->right, target, result); }
				else { getResult(node->left, target, result); }
			}

			int closestValue(TreeNode* root, double target) {
				double result = (double)root->val;
				getResult(root, target, result);
				return (int)result;
			}
		}
		void Main()
		{
			print(closestValue(new TreeNode(1), 4.428571));
		}
	}
}