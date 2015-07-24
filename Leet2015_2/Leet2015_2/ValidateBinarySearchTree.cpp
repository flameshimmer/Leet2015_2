#include "stdafx.h"

//Given a binary tree, determine if it is a valid binary search tree(BST).
//
//Assume a BST is defined as follows :
//
//The left subtree of a node contains only nodes with keys less than the node's key.
//The right subtree of a node contains only nodes with keys greater than the node's key.
//Both the left and right subtrees must also be binary search trees.

namespace Solution2
{
    namespace ValidateBinarySearchTree
    {
		bool isValid(TreeNode* node, long long& minV, long long& maxV)
		{
			if (!node) { return true; }
			long long val = node->val;
			if (val <= minV || val >= maxV) { return false; }
			return isValid(node->left, minV, val) && isValid(node->right, val, maxV);
		}
          
		bool isValidBST(TreeNode* root) {
			if (!root) { return true; }
			long long minV = INT_MIN;
			long long maxV = INT_MAX;
			minV--; maxV++;
			return isValid(root, minV, maxV);
		}
     
        void Main()
        {
			TreeNode* root = new TreeNode(0);
			print(isValidBST(root));
        }
    }
}
