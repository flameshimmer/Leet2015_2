#include "stdafx.h"

//Given a linked list, return the node where the cycle begins.If there is no cycle, return null.
//
//Follow up :
//Can you solve it without using extra space ?

namespace Solution2
{
    namespace LinkedListCycleII
    {
     
		ListNode *detectCycle(ListNode *head) 
		{
			if (!head || !head->next) { return NULL; }
			ListNode* fast = head->next->next;
			ListNode* slow = head->next;

			while (fast && fast->next)
			{
				if (fast == slow) { break; }
				fast = fast->next->next;
				slow = slow->next;
			}
			if (!fast || !fast->next) { return NULL; }
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
     
     
        void Main()
        {
			ListNode* list = createList({1});
			list->next = list;
			print(detectCycle(list));
        }
    }
}
