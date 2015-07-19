#include "stdafx.h"

//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
//Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list 
//should become 1 -> 2 -> 4 after calling your function.

namespace Solution2
{
	namespace DeleteNodeInALinkedList
	{
		void deleteNode(ListNode* node) 
		{
			if (!node) { return; }
			ListNode* cur = node;
			ListNode* prev = NULL;
			while (cur->next)
			{
				cur->val = cur->next->val;
				prev = cur;
				cur = cur->next;
			}
			if (prev)
			{
				prev->next = NULL;
				delete cur;
			}			
		}

		void Main()
		{

		}
	}
}
