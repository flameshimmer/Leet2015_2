#include "stdafx.h"

//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5

namespace Solution2
{
    namespace ReverseNodesInKGroup
    {     
		ListNode* reverse(ListNode* head, ListNode* prev, ListNode* post)
		{
			if (!head || !head->next) { return post; }
			
			ListNode* cur = head;
			ListNode* next = cur->next;
			ListNode* nN;
			cur->next = NULL;
			while (next)
			{
				nN = next->next;
				next->next = cur;
				cur = next;
				next = nN;
			}

			prev->next = cur;
			head->next = post;
			return head;
		}


		ListNode* reverseKGroup(ListNode* head, int k) 
		{
			if (!head || !head->next || k < 2) { return head; }
			ListNode* dummy = new ListNode(-1);
			dummy->next = head;

			ListNode* prev = NULL;
			ListNode* start = NULL;
			ListNode* end = NULL;
			ListNode* post = NULL;
			
			ListNode* cur = dummy;
			int count = 0;
			while (count < k && cur && cur->next)
			{
				if (count == 0) { prev = cur; start = prev->next; }
				if (count == k - 1) 
				{ 
					end = cur->next; 
					post = end->next; 
					end->next = NULL;
					cur = reverse(start, prev, post);
					count = 0;
					continue;
				}
				count++;
				cur = cur->next;
			}
			return dummy->next;
		}
     
        void Main()
        {
			ListNode* l;
			l = createList({ 1, 2, 3, 4 });
			print(reverseKGroup(l, 2));

			l = createList({ 1, 2 });
			print(reverseKGroup(l, 2));
        }
    }
}
