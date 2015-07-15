#include "stdafx.h"

//Given a binary tree
//
//struct TreeLinkNode {
//	TreeLinkNode *left;
//	TreeLinkNode *right;
//	TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node.
//If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//Note:
//
//You may only use constant extra space.
//The input binary tree could be any binary tree
//For example,
//Given the following perfect binary tree,
//				1
//			   / \
//			  2   3
//			 / \   \
//			4  5    7
//After calling your function, the tree should look like :
//				1->NULL
//			   /  \
//			  2 -> 3->NULL
//			 / \    \
//			4-->5--->7->NULL

namespace Solution2
{
    namespace PopulatingNextRightPointersInEachNodeII
    {
		void connect(TreeLinkNode*& node, TreeLinkNode*& prev)
		{
			if (!node) { return; }
			if (!prev) { prev = node; }
			else
			{
				prev->next = node;
				prev = node;
			}
			connect(node->left, prev);
			connect(node->right, prev);
		}
		void connect(TreeLinkNode *root)
		{
			TreeLinkNode* prev = NULL;
			connect(root, prev);
		}

		namespace iterative
		{
			void connect(TreeLinkNode *root)
			{
				TreeLinkNode* cur = root;
				while (cur)
				{
					TreeLinkNode* prev = NULL;
					TreeLinkNode* next = NULL;
					while (cur)
					{
						if (cur->left)
						{
							if (!prev) { prev = cur->left; }
							else{ prev->next = cur->left; prev = cur->left; }
							if (!next) { next = cur->left; }
						}
						if (cur->right)
						{
							if (!prev) { prev = cur->right; }
							else{ prev->next = cur->right; prev = cur->right; }
							if (!next) { next = cur->right; }
						}
						cur = cur->next;
					}
					cur = next;
				}
			}
		}
     
        void Main()
        {
			TreeLinkNode* n1 = new TreeLinkNode(-1);
			TreeLinkNode* n2 = new TreeLinkNode(-7);
			TreeLinkNode* n3 = new TreeLinkNode(9);
			TreeLinkNode* n4 = new TreeLinkNode(-1);
			TreeLinkNode* n5 = new TreeLinkNode(-7);
			TreeLinkNode* n6 = new TreeLinkNode(8);
			TreeLinkNode* n7 = new TreeLinkNode(-9);

			n1->left = n2;
			n1->right = n3;
			n3->left = n4;
			n3->right = n5;
			n5->left = n6;
			n5->right = n7;
			connect(n1);
        }
    }
}
