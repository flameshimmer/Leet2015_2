#include "stdafx.h"

//You are given two linked lists representing two non - negative numbers.
//The digits are stored in reverse order and each of their nodes contain a single digit.
//Add the two numbers and return it as a linked list.
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//   Output : 7 -> 0 -> 8

namespace Solution2
{
    namespace AddTwoNumbers
    {
     
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
		{
			if (!l1 || !l2) { return l1 ? l1 : l2; }

			int carry = 0;
			ListNode* head = NULL;
			ListNode* tail = NULL;

			while (l1 || l2 || carry > 0)
			{
				int val1 = l1 ? l1->val : 0;
				int val2 = l2 ? l2->val : 0;
				int sum = (val1 + val2 + carry) % 10;
				carry = (val1 + val2 + carry) / 10;
				if (l1) { l1 = l1->next; }
				if (l2) { l2 = l2->next; }

				ListNode* newNode = new ListNode(sum);
				if (!head) { head = newNode; }
				else { tail->next = newNode; }
				tail = newNode;
			}
			return head;
		}
     
     
        void Main()
        {
			ListNode* l1 = createList({2, 4, 3});
			ListNode* l2 = createList({ 5, 6, 4 });
			print(addTwoNumbers(l1, l2));
         
        }
    }
}
