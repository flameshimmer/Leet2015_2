#include "stdafx.h"

//Sort a linked list in O(n log n) time using constant space complexity.

namespace Solution2
{
    namespace SortList
    {   
		ListNode* merge(ListNode* l1, ListNode* l2)
		{
			if (!l1 && !l2) { return NULL; }
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			ListNode* newHead = NULL;
			ListNode* newTail = NULL;
			while (l1 && l2)
			{
				if (l1->val < l2->val)
				{
					if (!newHead) { newHead = l1; }
					else { newTail->next = l1; }
					newTail = l1;
					l1 = l1->next;
				}
				else
				{
					if (!newHead) { newHead = l2; }
					else { newTail->next = l2; }
					newTail = l2;
					l2 = l2->next;
				}
			}
			newTail->next = l1 ? l1 : l2;
			return newHead;
		}

		ListNode* sortList(ListNode* head) {
			if (!head || !head->next) { return head; }

			ListNode* slow = head;
			ListNode* fast = head;
			ListNode* prev = NULL;
			while (fast && fast->next)
			{
				fast = fast->next->next;
				prev = slow;
				slow = slow->next;
			}
			ListNode* l1 = head;
			ListNode* l2 = prev->next;
			prev->next = NULL;

			l1 = sortList(l1);
			l2 = sortList(l2);
			return merge(l1, l2);
		}
        
		void Main()
        {
			print(sortList(createList({ 2, 1 })));
        }
    }
}
