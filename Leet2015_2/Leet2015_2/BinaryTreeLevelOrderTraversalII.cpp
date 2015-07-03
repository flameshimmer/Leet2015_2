#include "stdafx.h"

//Given a binary tree, return the bottom - up level order traversal 
//of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//		3
//	   / \
//	  9  20
//		 / \
//	    15   7
//return its bottom - up level order traversal as :
//[
//	[15, 7],
//	[9, 20],
//	[3]
//]
namespace Solution2
{
    namespace BinaryTreeLevelOrderTraversalII
    {
    
		vector<vector<int>> levelOrderBottom(TreeNode* root) {
			vector<vector<int>> results;
			if (!root) { return results; }

			queue<TreeNode*> q;
			q.push(root);
			int count = 1;
			int nextCount = 0;
			vector<int> result;

			while (!q.empty())
			{
				TreeNode* cur = q.front();
				result.push_back(cur->val);
				q.pop();
				count--;
				if (cur->left) { q.push(cur->left); nextCount++; }
				if (cur->right) { q.push(cur->right); nextCount++; }

				if (count == 0)
				{
					results.push_back(result);
					count = nextCount;
					nextCount = 0;
					result.clear();
				}
			}
			reverse(results.begin(), results.end());
			return results;
		}
     
     
        void Main()
        {
         
        }
    }
}
