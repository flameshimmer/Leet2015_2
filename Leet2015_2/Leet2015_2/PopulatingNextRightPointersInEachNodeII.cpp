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
		void connect(TreeLinkNode *root)
		{
			if (!root) { return; }
			TreeLinkNode* child = NULL;
			if (root->left) { root->left->next = root->right; child = root->left; }
			if (root->right) { child = root->right; }

			if (child)
			{
				TreeLinkNode* cur = root->next;
				while (cur)
				{
					if (cur->left) { child->next = cur->left; break; }
					if (cur->right) { child->next = cur->right; break; }
					cur = cur->next;
				}
			}
			connect(root->right);
			connect(root->left);
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
			TreeLinkNode* n1 = new TreeLinkNode(2);
			TreeLinkNode* n2 = new TreeLinkNode(1);
			TreeLinkNode* n3 = new TreeLinkNode(3);
			TreeLinkNode* n4 = new TreeLinkNode(0);
			TreeLinkNode* n5 = new TreeLinkNode(7);
			TreeLinkNode* n6 = new TreeLinkNode(9);
			TreeLinkNode* n7 = new TreeLinkNode(1);
			TreeLinkNode* n8 = new TreeLinkNode(2);
			TreeLinkNode* n9 = new TreeLinkNode(1);
			TreeLinkNode* n10 = new TreeLinkNode(0);
			TreeLinkNode* n11 = new TreeLinkNode(8);
			TreeLinkNode* n12 = new TreeLinkNode(8);
			TreeLinkNode* n13 = new TreeLinkNode(7);

			n1->left = n2;
			n1->right = n3;

			n2->left = n4;
			n2->right = n5;


			n3->left = n6;
			n3->right = n7;

			n4->left = n8;

			n5->left = n9;
			n5->right = n10;

			n7->left = n11;
			n7->right = n12;

			n10->left = n13;

			connect(n1);
        }
    }
}
