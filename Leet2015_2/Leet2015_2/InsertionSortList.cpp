#include "stdafx.h"

//Sort a linked list using insertion sort.

namespace Solution2
{
    namespace InsertionSortList
    {     
		ListNode* insertionSortList(ListNode* head) 
		{
			if (!head || !head->next) { return head; }
			ListNode* dummy = new ListNode(INT_MIN);
			dummy->next = head;
			ListNode* cur = head;
			
			while (cur->next)
			{
				ListNode* scan = dummy;
				while (scan->next != cur->next)
				{
					if (scan->next->val > cur->next->val)
					{
						ListNode* temp = cur->next;
						cur = cur->next->next;
						temp->next = scan->next;
						scan->next = temp;
						break;
					}
				}
				if (scan->next == cur->next)
				{
					cur = cur->next;
				}
			}


			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}
     
        void Main()
        {
			ListNode* input = createList({2, 1});
			print(insertionSortList(input));
        }
    }
}
