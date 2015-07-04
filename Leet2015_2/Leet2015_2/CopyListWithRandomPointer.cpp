#include "stdafx.h"

//A linked list is given such that each node contains an additional random 
//pointer which could point to any node in the list or null.
//
//Return a deep copy of the list.

namespace Solution2
{
    namespace CopyListWithRandomPointer
    {
     
		RandomListNode *copyRandomList(RandomListNode *head) 
		{
			if (!head) { return NULL; }

			RandomListNode* cur = head;
			while (cur)
			{
				RandomListNode* newNode = new RandomListNode(cur->label);
				newNode->next = cur->next;
				cur->next = newNode;
				cur = cur->next->next;
			}

			cur = head;
			while (cur)
			{
				if (cur->random)
				{
					cur->next->random = cur->random->next;
				}
				cur = cur->next->next;
			}

			cur = head;
			RandomListNode* copyHead = NULL;
			RandomListNode* copyTail = NULL;
			while (cur)
			{
				if (!copyHead) { copyHead = cur->next; }
				else { copyTail->next = cur->next; }
				copyTail = cur->next;
				cur->next = cur->next->next;
				cur = cur->next;
			}
			copyTail->next = NULL;
			return copyHead;
		}
     
     
        void Main()
        {
         
        }
    }
}
