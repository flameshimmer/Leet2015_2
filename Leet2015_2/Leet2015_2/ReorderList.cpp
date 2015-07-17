#include "stdafx.h"

//Given a singly linked list L : L0→L1→…→Ln - 1→Ln,
//reorder it to : L0→Ln→L1→Ln - 1→L2→Ln - 2→…
//
//You must do this in - place without altering the nodes' values.
//
//For example,
//Given{ 1, 2, 3, 4 }, reorder it to{ 1, 4, 2, 3 }

namespace Solution2
{
    namespace ReorderList
    {     
		ListNode* reverse(ListNode* head)
		{
			if (!head || !head->next) { return head; }
			
			ListNode* cur = head;
			ListNode* next = head->next;
			ListNode* nextNext;
			cur->next = NULL;
			while (next)
			{
				nextNext = next->next;
				next->next = cur;
				cur = next;
				next = nextNext;
			}
			return cur;
		}

		void reorderList(ListNode* head) {
			if (!head || !head->next) { return; }

			ListNode* fast = head;
			ListNode* slow = head;
			while (fast && fast->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			
			ListNode* l1 = head;
			ListNode* l2 = slow->next;
			slow->next = NULL;
			l2 = reverse(l2);

			ListNode* newHead = head;
			ListNode* newTail = head;
			bool isL2Turn = true;
			l1 = l1->next;
			while (l2 || l1)
			{
				if (l2 && isL2Turn)
				{
					newTail->next = l2;
					newTail = l2;
					l2 = l2->next;
				}
				else if (l1 && !isL2Turn)
				{
					newTail->next = l1;
					newTail = l1;
					l1 = l1->next;
				}
				isL2Turn = !isL2Turn;
			}
			newTail->next = NULL;
		}
     
        void Main()
        {
         
        }
    }
}
