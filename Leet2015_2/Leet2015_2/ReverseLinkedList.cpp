#include "stdafx.h"

//Reverse a singly linked list.

namespace Solution2
{
    namespace ReverseLinkedList
    {
     
		ListNode* reverseList(ListNode* head) 
		{
			if (!head || !head->next){ return head;}

			ListNode* cur = head;
			ListNode* next = head->next;
			ListNode* nN;
			cur->next = NULL;
			while (next)
			{
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}
			return cur;
		}
     
     
        void Main()
        {
         
        }
    }
}
