#include "stdafx.h"
#include <functional>
//Merge k sorted linked lists and return it as one sorted list.
//Analyze and describe its complexity.

namespace Solution2
{
	namespace MergeKSortedLists
	{

		namespace divideAndConqure
		{
			ListNode* merge2Lists(ListNode* l1, ListNode* l2)
			{
				if (!l1 && !l2) { return NULL; }
				if (!l1 || !l2) { return l1 ? l1 : l2; }

				ListNode* head = NULL;
				ListNode* tail = NULL;
				while (l1 && l2)
				{
					ListNode* next = (l1->val < l2->val) ? l1 : l2;
					if (!head) { head = next; }
					else { tail->next = next; }
					tail = next;
					if (next == l1) { l1 = l1->next; }
					else { l2 = l2->next; }
				}
				if (l1 || l2)
				{
					tail->next = l1 ? l1 : l2;
				}
				return head;
			}

			ListNode* mergeKLists(vector<ListNode*>& lists)
			{
				int len = lists.size();
				if (len == 0) { return NULL; }
				if (len == 1) { return lists[0]; }

				while (lists.size() > 1)
				{
					ListNode* l1 = lists[0];
					ListNode* l2 = lists[1];
					ListNode* merged = merge2Lists(l1, l2);
					lists.erase(lists.begin(), lists.begin() + 2);
					lists.push_back(merged);
				}
				return lists[0];
			}
		}
		namespace stdHeap{
			static bool CompFunc(ListNode* a, ListNode* b) { return a->val > b->val; }

			ListNode* mergeKLists(vector<ListNode*>& lists)
			{
				int len = lists.size();
				if (len == 0) { return NULL; }

				ListNode* head = NULL;
				ListNode* tail = NULL;
				priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> queue(CompFunc);

				for (int i = 0; i < len; i++)
				{
					if (lists[i])
					{
						queue.push(lists[i]);
					}
				}

				while (!queue.empty())
				{
					ListNode* smallestNode = queue.top();
					queue.pop();
					if (smallestNode->next) { queue.push(smallestNode->next); }

					if (!head) { head = smallestNode; }
					else { tail->next = smallestNode; }
					tail = smallestNode;
				}
				return head;
			}
		}
		
		void swap(vector<ListNode*>& lists, int a, int b)
		{
			ListNode* temp = lists[a];
			lists[a] = lists[b];
			lists[b] = temp;
		}

		void heapify(vector<ListNode*> lists, int i, int len)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left >= len) { return; }
			int minIndex = 0;
			if (right >= len) { minIndex = left; }
			else
			{
				minIndex = lists[left]->val < lists[right]->val ? left : right;
			}

			if (lists[i]->val > lists[minIndex]->val)
			{
				swap(lists, i, minIndex);
				heapify(lists, minIndex, len);
			}
		}

		void buildHeap(vector<ListNode*> lists)
		{
			int len = lists.size();
			for (int i = (len - 1) / 2; i >= 0; i--)
			{
				heapify(lists, i, len);
			}
		}


		ListNode* mergeKLists(vector<ListNode*>& lists)
		{
			int len = lists.size();
			if (len == 0) { return NULL; }
			if (len == 1) { return lists[0]; }

			for (int i = len - 1; i >= 0; i--)
			{
				if (!lists[i]) { lists.erase(lists.begin() + i); }
			}

			buildHeap(lists);			
			ListNode* head = NULL;
			ListNode* tail = NULL;			
			
			while (lists.size() > 0)
			{
				ListNode* top = lists[0];
				if (!head) { head = top; }
				else { tail->next = top; }
				tail = top;

				if (lists[0]->next) { lists[0] = lists[0]->next; }
				else
				{
					swap(lists, 0, lists.size() - 1);
					lists.pop_back();
				}
				heapify(lists, 0, lists.size());
			}
			return head;
		}

		void Main()
		{
			vector<ListNode*> input;
			input = { 
				createList({ -10, -9, -9, -3, -1, -1, 0 }),
				NULL, 
				createList({ -5 }),
				createList({ 4 }), 
				createList({ -8}),
				NULL,
				createList({ -9, -6, -5, -4, -2, 2, 3 }),
				createList({ -3, -3, -2, -1, 0 })
			};
			print(mergeKLists(input));

			input = { NULL, createList({ -1, 5, 11 }), NULL, createList({ 6, 10 }) };
			print(mergeKLists(input));

			input = { createList({ 1 }), createList({ 0 }) };
			print(mergeKLists(input));
		}
	}
}
