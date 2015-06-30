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
		namespace other
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

			ListNode* reverseBetween(ListNode* head, int m, int n)
			{
				if (!head || !head->next) { return head; }

				ListNode* dummy = new ListNode(-1);

				dummy->next = head;
				ListNode* cur = dummy;
				ListNode* prev = NULL;
				ListNode* end = NULL;

				m--;
				n--;
				int step = 0;
				while (cur)
				{
					if (step == m)
					{
						prev = cur;
					}
					if (step == n)
					{
						end = cur->next;
						break;
					}
					cur = cur->next;
					step++;
				}

				if (prev->next == NULL || end == NULL || prev->next == end)
				{
					return dummy->next;
				}
				ListNode* next = end->next;
				end->next = NULL;

				ListNode* newTail = prev->next;
				ListNode* newHead = reverse(prev->next);
				prev->next = newHead;
				newTail->next = next;

				return dummy->next;
			}

		}
     
		ListNode* reverseBetween(ListNode* head, int m, int n) {
			if (!head || !head->next || m == n) { return head; }

			ListNode* dummy = new ListNode(-1);
			dummy->next = head;

			ListNode* pre = dummy;
			for (int i = 0; i < m - 1; i++)
			{
				pre = pre->next;
			}

			ListNode* cur = pre->next;
			for (int i = 0; i < n - m; i++)
			{
				ListNode* move = cur->next;
				cur->next = move->next;
				move->next = pre->next;
				pre->next = move;
			}
			return dummy->next;
		}
     
        void Main()
        {
			ListNode* l;
			l = createList({ 3, 5 });
			print(reverseBetween(l, 1, 2));

			l = createList({ 3, 5 });
			print(reverseBetween(l, 2, 2));
        }
    }
}
