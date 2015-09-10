#include "stdafx.h"

//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space.You may not modify 
//the values in the list, only nodes itself can be changed.


namespace Solution2
{
    namespace SwapNodesInPairs
    {     
		namespace recursion
		{
			ListNode* swapPairs(ListNode* head)
			{
				if (!head || !head->next) { return head; }

				ListNode* cur = head;
				ListNode* next = head->next;
				ListNode* nN = next->next;

				ListNode* remains = swapPairs(nN);
				cur->next = remains;
				next->next = cur;
				return next;
			}
		}

		ListNode* swapPairs(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* result = head->next;

			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nN;			
			ListNode* prev = NULL;

			while (next)
			{
				nN = next->next;
				next->next = cur;
				cur->next = nN;

				if (prev){ prev->next = next; }
				prev = cur;

				cur = nN;
				next = NULL;
				if (cur) { next = nN->next; }
			}
			return result;
		}


        void Main()
        {
			print(swapPairs(createList({ 1, 2, 3, 4 })));
			print(swapPairs(createList({ 1, 2 })));
			print(swapPairs(createList({ 1, 2, 3})));
			
        }
    }
}
