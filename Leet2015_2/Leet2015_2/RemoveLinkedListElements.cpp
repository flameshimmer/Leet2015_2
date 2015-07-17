#include "stdafx.h"

//Remove all elements from a linked list of integers that have value val.
//
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5

namespace Solution2
{
    namespace RemoveLinkedListElements
    {
     
		ListNode* removeElements(ListNode* head, int val) {
			if (!head) { return NULL; }

			ListNode* newHead = NULL;
			ListNode* newTail = NULL;
			ListNode* cur = head;
			while (cur)
			{
				if (cur->val != val)
				{ 
					if (!newHead) { newHead = cur; }
					else{ newTail->next = cur; }
					newTail = cur;
				}
				cur = cur->next;
			}
			if (newTail) { newTail->next = NULL; }
			return newHead;
		}
     
		namespace other
		{
			ListNode* removeElements(ListNode* head, int val) {
				if (!head) { return NULL; }
				ListNode* dummy = new ListNode(-1);
				dummy->next = head;

				ListNode* cur = dummy;
				while (cur->next)
				{
					if (cur->next->val == val)
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
				ListNode* result = dummy->next;
				delete dummy;
				return result;
			}
		}
        void Main()
        {
         
        }
    }
}
