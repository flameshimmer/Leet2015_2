#include "stdafx.h"

//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
//Follow up :
//What if the BST is modified(insert / delete operations) often and you need to find the kth smallest frequently ? How would you optimize the kthSmallest routine ?

namespace Solution2
{
	namespace KthSmallestElementInABST
	{
		void getKth(TreeNode* node, int& k, int& v)
		{
			if (!node || k == 0) { return; }
			getKth(node->left, k, v);
			if (k == 1){ v = node->val;}
			k--;
			getKth(node->right, k, v);
		}
		
		int kthSmallest(TreeNode* root, int k) {
			int result = 0;
			getKth(root, k, result);
			return result;
		}


		namespace inOrderTraversal{
			int kthSmallest(TreeNode* root, int k) {
				if (!root) { return 0; }

				stack<TreeNode*> s;
				TreeNode* cur = root;
				int count = 0;
				while (!s.empty() || cur)
				{
					if (cur)
					{
						s.push(cur);
						cur = cur->left;
					}
					else
					{
						TreeNode* top = s.top();
						s.pop();
						count++;
						if (count == k) { return top->val; }
						cur = top->right;
					}
				}
				return 0;
			}
		}
		void Main()
		{
		
		}

	}
}