#include "stdafx.h"

//Write a program to find the node at which the intersection of two singly linked lists begins.
//
//
//For example, the following two linked lists :
//
//A : a1 → a2
//	↘
//	c1 → c2 → c3
//	↗
//B : b1 → b2 → b3
//	begin to intersect at node c1.
//
//
//Notes :
//
//	  If the two linked lists have no intersection at all, return null.
//	  The linked lists must retain their original structure after the function returns.
//	  You may assume there are no cycles anywhere in the entire linked structure.
//	  Your code should preferably run in O(n) time and use only O(1) memory.
//  Credits :
//		  Special thanks to @stellari for adding this problem and creating all test cases.

namespace Solution2
{
    namespace IntersectionOfTwoLinkedLists
    {
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
		{
			int lenA = 0;
			ListNode* cur = headA;
			while (cur) { lenA++; cur = cur->next; }

			int lenB = 0;
			cur = headB;
			while (cur) { lenB++; cur = cur->next; }

			int diff = lenA > lenB ? lenA - lenB : lenB - lenA;
			ListNode* longer = lenA > lenB ? headA : headB;
			ListNode* shorter = lenA > lenB ? headB : headA;

			for (int i = 0; i < diff; i++) { longer = longer->next; }
			while (longer && shorter)
			{
				if (longer == shorter) { return longer; }
				longer = longer->next;
				shorter = shorter->next;
			}
			return NULL;
		}
     
        void Main()
        {
         
        }
    }
}
