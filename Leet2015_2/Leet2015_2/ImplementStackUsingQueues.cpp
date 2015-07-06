#include "stdafx.h"

//Implement the following operations of a stack using queues.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//empty() --Return whether the stack is empty.
//Notes:
//You must use only standard operations of a queue -- which means only push to back, 
//peek / pop from front, size, and is empty operations are valid.
//Depending on your language, queue may not be supported natively.
//You may simulate a queue by using a list or deque(double - ended queue), as long as you use only standard operations of a queue.
//You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).

namespace Solution2
{
    namespace ImplementStackUsingQueues
    {
		class Stack {
		private:
			queue<int> q1;
			queue<int> q2;
			int last;
		public:
			// Push element x onto stack.
			void push(int x) {
				if (q2.size() > 0) { swap(q1, q2); }
				q1.push(x);
				last = x;
			}

			// Removes the element on top of the stack.
			void pop() {
				if (q2.size() > 0) { swap(q1, q2); }
				while (!q1.empty())
				{
					int top = q1.front();
					if (q1.size() > 1)
					{
						last = top;
						q2.push(top);
					}					
					q1.pop();
				}
			}

			// Get the top element.
			int top() {
				return last;
			}

			// Return whether the stack is empty.
			bool empty() {
				return q1.empty() && q2.empty();
			}
		};
     
        void Main()
        {
         
        }
    }
}
