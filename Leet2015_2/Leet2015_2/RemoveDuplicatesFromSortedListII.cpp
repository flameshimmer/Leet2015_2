#include "stdafx.h"

//Given a sorted linked list, delete all nodes that have duplicate 
//numbers, leaving only distinct numbers from the original list.
//
//For example,
//Given 1->2->3->3->4->4->5, return 1->2->5.
//Given 1->1->1->2->3, return 2->3

namespace Solution2
{
    namespace RemoveDuplicatesFromSortedListII
    {     
		ListNode* deleteDuplicates(ListNode* head) 
		{
			if (!head || !head->next) { return head; }
			ListNode* newHead = NULL;
			ListNode* newTail = NULL;
			ListNode* cur = head;
						
			while (cur)
			{
				int count = 1;
				while (cur->next && cur->val == cur->next->val)
				{
					count++;
					cur = cur->next;
				}
				if (count == 1)
				{
					if (!newHead) { newHead = cur; }
					else { newTail->next = cur; }
					newTail = cur;
				}
				cur = cur->next;
			}
			if (newTail) { newTail->next = NULL; }
			return newHead;
		}
     
        void Main()
        {
			print(deleteDuplicates(createList({ 1, 2, 2 })));
        }
    }
}
