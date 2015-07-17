#include "stdafx.h"

//Given a list, rotate the list to the right by k places, where k is non - negative.
//
//For example :
//Given 1->2->3->4->5->NULL and k = 2,
//return 4->5->1->2->3->NULL.

namespace Solution2
{
    namespace RotateList
    {
     
		ListNode* rotateRight(ListNode* head, int k) {
			if (!head || !head->next || k == 0) { return head; }
			int len = 0;
			ListNode* cur = head;
			ListNode* tail = NULL;
			while (cur){ len++; tail = cur; cur = cur->next; }
			tail->next = head;

			k %= len;
			int v = len - k - 1;
			cur = head;
			for (int i = 0; i < v; i++) { cur = cur->next; }
			ListNode* newHead = cur->next;
			cur->next = NULL;
			return newHead;
		}
     
        void Main()
        {
			print(rotateRight(createList({ 0, 1 }), 1));
        }
    }
}
