#include "stdafx.h"

//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.

namespace Solution2
{
    namespace ConstructBinaryTreeFromPreorderAndInorderTraversal
    {

		TreeNode* buildTreeInternal(vector<int>& pre, vector<int>& in, int start, int end, int& index, unordered_map<int, int>& map)
		{
			if (start > end) { return NULL; }
			int i = map[pre[index]];

			TreeNode* newNode = new TreeNode(in[i]);
			index++;
			newNode->left = buildTreeInternal(pre, in, start, i - 1, index, map);
			newNode->right = buildTreeInternal(pre, in, i + 1, end, index, map);
			return newNode;
		}


		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int len = preorder.size();
			int index = 0;
			unordered_map<int, int>map;
			for (int i = 0; i<len; i++)
			{
				map[inorder[i]] = i;
			}

			return buildTreeInternal(preorder, inorder, 0, len - 1, index, map);
		}
     
        void Main()
        {
			buildTree(createVector({ 1, 2 }), createVector({ 2, 1 }));
        }
    }
}
