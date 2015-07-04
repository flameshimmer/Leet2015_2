#include "stdafx.h"

//Given a singly linked list where elements are sorted in ascending order, 
//convert it to a height balanced BST.

namespace Solution2
{
    namespace ConvertSortedListToBinarySearchTree
    {
     
		TreeNode* helper(ListNode*& head, int start, int end)
		{
			if (!head || start > end) { return NULL; }

			int mid = start + (end - start) / 2;
			TreeNode* left = helper(head, start, mid - 1);
			TreeNode* newNode = new TreeNode(head->val);
			newNode->left = left;
			head = head->next;
			newNode->right = helper(head, mid + 1, end);
			return newNode;
		}

		TreeNode* sortedListToBST(ListNode* head) 
		{
			if (!head) { return NULL; }
			int len = 0;
			ListNode* cur = head;
			while (cur)
			{
				len++;
				cur = cur->next;
			}
			return helper(head, 0, len - 1);
		}
     
     
        void Main()
        {
			ListNode* list = createList({1, 2, 3, 4, 5});
			print(sortedListToBST(list));
        }
    }
}
