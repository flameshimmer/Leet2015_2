#include "stdafx.h"

//Given a linked list, determine if it has a cycle in it.
//
//Follow up :
//Can you solve it without using extra space ?

namespace Solution2
{
    namespace LinkedListCycle
    {
		bool hasCycle(ListNode *head) 
		{
			if (!head || !head->next) { return false; }

			ListNode* slow = head;
			ListNode* fast = head;
			
			while (fast && fast->next)
			{
				if (fast->next == slow) { return true; }
				slow = slow->next;
				fast = fast->next->next;
			}
			return false;
		}
     
        void Main()
        {
         
        }
    }
}
