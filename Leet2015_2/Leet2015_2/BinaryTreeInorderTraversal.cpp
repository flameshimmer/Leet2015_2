#include "stdafx.h"

//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example :
//Given binary tree{ 1, #, 2, 3 },
//		1
//       \
//		  2
//		 /
//		3
//return[1, 3, 2].
//
//Note: Recursive solution is trivial, could you do it iteratively ?
//
namespace Solution2
{
    namespace BinaryTreeInorderTraversal
    {
		vector<int> inorderTraversal(TreeNode* root) 
		{
			vector<int> result;
			if (!root) { return result; }

			TreeNode* cur = root;
			stack<TreeNode*> s;
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
					result.push_back(top->val);
					cur = top->right;
				}
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
