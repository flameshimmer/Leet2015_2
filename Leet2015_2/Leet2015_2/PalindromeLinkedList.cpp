#include "stdafx.h"

//Given a singly linked list, determine if it is a palindrome.
//
//Follow up :
//Could you do it in O(n) time and O(1) space ?

namespace Solution2
{
	namespace PalindromeLinkedList
	{

		ListNode* reverse(ListNode* head)
		{
			if (!head || !head->next) { return head; }
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
			return cur;
		}


		bool isPalindrome(ListNode* head) 
		{
			if (!head || !head->next) { return true; }

			ListNode* slow = head;
			ListNode* fast = head;
			ListNode* prev = NULL;
			while (fast && fast->next)
			{
				prev = slow;
				slow = slow->next;
				fast = fast->next->next;
			}

			ListNode* l1 = head;
			ListNode* l2 = prev->next;
			prev->next = NULL;

			l2 = reverse(l2);
			while (l1 && l2)
			{
				if (l1->val != l2->val) { return false; }
				l1 = l1->next;
				l2 = l2->next;
			}
			return true;
		}

		void Main()
		{
			print(isPalindrome(createList({ 1, 1, 2, 1 })));
		}
	}
}