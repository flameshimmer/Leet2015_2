#include "stdafx.h"

//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

namespace Solution2
{
    namespace ConstructBinaryTreeFromInorderAndPostorderTraversal
    {
     
		TreeNode* buildTreeInternal(vector<int>& in, vector<int>& post, int start, int end, int& index)
		{
			if (start > end) { return NULL; }
			int cur = post[index];
			int i;
			for (i = start; i < end; i++)
			{
				if (in[i] == cur) { break; }
			}
			index--;
			TreeNode* newNode = new TreeNode(cur);
			TreeNode* right = buildTreeInternal(in, post, i + 1, end, index);
			TreeNode* left = buildTreeInternal(in, post, start, i - 1, index);
			newNode->left = left;
			newNode->right = right;
			return newNode;
		}

		TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
		{
			int len = inorder.size();			
			int index = len - 1;
			return buildTreeInternal(inorder, postorder, 0, len - 1, index);
		}
     
     
        void Main()
        {
         
        }
    }
}
