#include "stdafx.h"

//Given a binary tree, return the zigzag level order traversal of its nodes'
//values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example :
//Given binary tree{ 3, 9, 20, #, #, 15, 7 },
//			 3
//			/ \
//		   9  20
//		  / \
//		15   7
//return its zigzag level order traversal as :
//[
//	[3],
//	[20, 9],
//	[15, 7]
//]

namespace Solution2
{
    namespace BinaryTreeZigzagLevelOrderTraversal
    {     
		vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
		{
			vector<vector<int>> results;
			if (!root) { return results; }

			vector<int> result;
			queue<TreeNode*> q;
			q.push(root);
			int count =	1;
			int nextCount = 0;
			bool leftToRight = true;

			while (!q.empty())
			{
				TreeNode* top = q.front();
				result.push_back(top->val);
				q.pop();

				if (top->left) { q.push(top->left); nextCount++; }
				if (top->right) { q.push(top->right); nextCount++; }

				count--;
				if (count == 0)
				{
					if (!leftToRight) { reverse(result.begin(), result.end());}
					results.push_back(result);
					result.clear();
					count = nextCount;
					nextCount = 0;
					leftToRight = !leftToRight;
				}
			}
			return results;
		}     
     
        void Main()
        {
         
        }
    }
}
