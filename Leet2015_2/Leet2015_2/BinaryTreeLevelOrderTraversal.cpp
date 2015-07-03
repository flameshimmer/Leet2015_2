#include "stdafx.h"

//Given a binary tree, return the level order traversal of its nodes'
//values. (ie, from left to right, level by level).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//	  3
//   / \
//  9  20
// / \
//15   7
//
//return its level order traversal as :
//[
//	[3],
//	[9, 20],
//	[15, 7]
//]

namespace Solution2
{
    namespace BinaryTreeLevelOrderTraversal
    {
     
		vector<vector<int>> levelOrder(TreeNode* root) 
		{
			vector<vector<int>>results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);
			int levelCount = 0;
			int count = 1;
			vector<int> result;

			while (!q.empty())
			{
				TreeNode* cur = q.front();
				result.push_back(cur->val);
				q.pop();
				count--;

				if (cur->left) { q.push(cur->left); levelCount++; }
				if (cur->right) { q.push(cur->right); levelCount++; }

				if (count == 0)
				{
					results.push_back(result);
					result.clear();
					count = levelCount;
					levelCount = 0;
				}
			}
			return results;
		}
     
     
        void Main()
        {
			TreeNode* n = new TreeNode(1);
			print(levelOrder(n));
         
        }
    }
}
