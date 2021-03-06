#include "stdafx.h"

//Given a linked list and a value x, partition it such that all 
//nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes 
//in each of the two partitions.
//
//For example,
//Given 1->4->3->2->5->2 and x = 3,
//return 1->2->2->4->3->5.

namespace Solution2
{
    namespace PartitionList
    {     
		ListNode* partition(ListNode* head, int x) {
			if (!head || !head->next) { return head; }
			
			ListNode* less = NULL;
			ListNode* lessTail = NULL;
			ListNode* more = NULL;
			ListNode* moreTail = NULL;

			ListNode* cur = head;
			while (cur)
			{
				if (cur->val < x)
				{
					if (!less) { less = cur; }
					else { lessTail->next = cur; }
					lessTail = cur;
				}
				else
				{
					if (!more) { more = cur; }
					else { moreTail->next = cur;}
					moreTail = cur;
				}
				cur = cur->next;
			}
			if (lessTail) { lessTail->next = more; }
			if (moreTail) { moreTail->next = NULL; }

			return less == NULL ? more : less;
		}
     
        void Main()
        {
         
        }
    }
}
