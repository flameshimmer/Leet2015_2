#include "stdafx.h"

//Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
//
//For example,
//Given n = 3, your program should return all 5 unique BST's shown below.
//
//	1         3     3      2      1
//	 \       /     /      / \      \
//	  3     2     1      1   3      2
//	 /     /       \                 \
//	2     1         2                 3

namespace Solution2
{
    namespace UniqueBinarySearchTreesII
    {   
		vector<TreeNode*> generate(int startVal, int n)
		{
			vector<TreeNode*> results;
			if (n == 0) { results.push_back(NULL); return results; }
			if (n == 1) { results.push_back(new TreeNode(startVal)); return results; }

			for (int i = 0; i <= n - 1; i++)
			{
				vector<TreeNode*> left = generate(startVal, i);
				vector<TreeNode*> right = generate(startVal + i + 1, n - 1 - i);
				for (TreeNode* l : left)
				{
					for (TreeNode* r : right)
					{
						TreeNode* root = new TreeNode(startVal+ i);
						root->left = l;
						root->right = r;
						results.push_back(root);
					}
				}
			}
			return results;
		}
		vector<TreeNode*> generateTrees(int n) 
		{
			return generate(1, n);
		}

        void Main()
        {
			generateTrees(3);
        }
    }
}
