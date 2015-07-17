#include "stdafx.h"

//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//For example,
//Given 1->1->2, return 1->2.
//Given 1->1->2->3->3, return 1->2->3.

namespace Solution2
{
    namespace RemoveDuplicatesfromSortedList
    {
     
		ListNode* deleteDuplicates(ListNode* head) {
			if (!head || !head->next) { return head; }
			
			ListNode* cur = head;
			while(cur->next)
			{
				if (cur->next->val == cur->val)
				{
					ListNode* temp = cur->next;
					cur->next = cur->next->next;
					delete temp;
				}
				else
				{
					cur = cur->next;
				}
			}
			return head;
		}
     
     
        void Main()
        {
         
        }
    }
}
