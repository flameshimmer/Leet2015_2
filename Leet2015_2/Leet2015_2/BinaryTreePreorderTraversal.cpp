#include "stdafx.h"

namespace Solution2
{
    namespace BinaryTreePreorderTraversal
    {
		vector<int> preorderTraversal(TreeNode* root) {
			vector<int> result;
			if (!root) { return result; }

			stack<TreeNode*> s;
			s.push(root);
			while (!s.empty())
			{
				TreeNode* top = s.top();
				s.pop();
				result.push_back(top->val);
				if (top->right) { s.push(top->right); }
				if (top->left) { s.push(top->left); }
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
