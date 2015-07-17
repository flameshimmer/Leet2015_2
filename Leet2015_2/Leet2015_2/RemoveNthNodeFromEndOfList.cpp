#include "stdafx.h"

//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note :
//	 Given n will always be valid.
//	 Try to do this in one pass.

namespace Solution2
{
    namespace RemoveNthNodeFromEndOfList
    {
     
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			if (!head) { return NULL; }

			ListNode* dummy = new ListNode(-1);
			dummy->next = head;

			ListNode* fast = dummy;
			for (int i = 0; i < n+1; i++)
			{
				fast = fast->next;
			}

			ListNode* slow = dummy;
			while (fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
			ListNode* temp = slow->next;
			slow->next = slow->next->next;
			delete temp;

			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
