#include "stdafx.h"


//Reverse a linked list from position m to n.Do it in - place and in one - pass.
//
//For example :
//Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//return 1->4->3->2->5->NULL.
//
//Note :
//	 Given m, n satisfy the following condition :
//1 ≤ m ≤ n ≤ length of list

namespace Solution2
{
    namespace ReverseLinkedListII
    {     
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if (!head || !head->next || m == n) { return head; }
			
			ListNode* dummy = new ListNode(-1);
			dummy->next = head;
			ListNode* prev = dummy;
			for (int i = 0; i < m - 1; i++)
			{
				prev = prev->next;
			}

			ListNode* cur = prev->next;
			for (int i = 0; i < n - m; i++)
			{
				ListNode* move = cur->next;
				cur->next = move->next;
				move->next = prev->next;
				prev->next = move;
			}
			
			ListNode* result = dummy->next;
			delete dummy;
			return result;
		}
     

		namespace other{
		
			void reverse(ListNode* root, ListNode*& newHead, ListNode*& newTail)
			{
				if (!root || !root->next) { newHead = newTail = root; }
				ListNode* cur = root;
				ListNode* next = root->next;
				ListNode* nN;
				cur->next = NULL;
				while (next)
				{
					nN = next->next;
					next->next = cur;
					cur = next;
					next = nN;
				}
				newHead = cur;
				newTail = root;
			}


			ListNode* reverseBetween(ListNode* head, int m, int n) {
				if (!head || !head->next) { return head; }

				ListNode* dummy = new ListNode(-1);
				dummy->next = head;

				ListNode* cur = dummy;
				int step = 0;
				while (cur && step < m - 1) { cur = cur->next; step++; }
				if (!cur) { return head; }
				ListNode* prev = cur;

				while (cur && step < n) { cur = cur->next; step++; }
				if (!cur) { return head; }
				ListNode* post = cur->next;
				cur->next = NULL;

				ListNode* newHead;
				ListNode* newTail;
				reverse(prev->next, newHead, newTail);
				prev->next = newHead;
				newTail->next = post;

				ListNode* result = dummy->next;
				delete dummy;
				return result;
			}
		}


        void Main()
        {
			ListNode* l;
			l = createList({ 3, 5 });
			print(other::reverseBetween(l, 1, 2));

			l = createList({ 3, 5 });
			print(reverseBetween(l, 2, 2));
        }
    }
}
