#include "stdafx.h"

//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.

namespace Solution2
{
    namespace MergeTwoSortedLists
    {
     
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			ListNode* head = NULL;
			ListNode* tail = NULL;
			
			while (l1 && l2)
			{
				ListNode* node = l1->val < l2->val ? l1 : l2;
				if (!head) { head = node; }
				else
				{
					tail->next = node;
				}
				tail = node;
				
				if (node == l1) { l1 = l1->next; }
				else { l2 = l2->next; }
			}

			if (l1 || l2)
			{
				tail->next = l1 ? l1 : l2;
			}
			return head;
		}
     
     
        void Main()
        {
         
        }
    }
}
