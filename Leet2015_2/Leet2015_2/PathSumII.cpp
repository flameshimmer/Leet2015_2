#include "stdafx.h"

//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//For example :
//Given the below binary tree and sum = 22,
//			5
//		   / \
//		  4   8
//		 /   / \
//		11  13  4
//	   / \     / \
//	  7   2   5   1
//return
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]
namespace Solution2
{
    namespace PathSumII
    {
		void pathSumImpl(TreeNode* node, int sum, vector<int>& result, vector<vector<int>>& results)
		{			
			if (!node->left && !node->right)
			{
				if (node->val == sum)
				{					
					result.push_back(node->val);
					results.push_back(result);
					result.pop_back();
				}
				return;
			}
			result.push_back(node->val);
			sum -= node->val;
			if (node->left)
			{
				pathSumImpl(node->left, sum, result, results);
			}
			if (node->right)
			{
				pathSumImpl(node->right, sum, result, results);
			}
			result.pop_back();
		}

		vector<vector<int>> pathSum(TreeNode* root, int sum) 
		{
			vector<vector<int>> results;
			if (!root) { return results; }
			vector<int> result;

			pathSumImpl(root, sum, result, results);
		}     
     
        void Main()
        {
         
        }
    }
}
