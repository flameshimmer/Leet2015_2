#include "stdafx.h"

namespace Solution2
{
	namespace ImplementQueueUsingStacks
	{
		class Queue {
		public:
			stack<int>	s1;
			stack<int>	s2;
			// Push element x to the back of queue.
			void push(int x) {
				if (s2.size() > s1.size())
				{
					while (!s2.empty()) { s1.push(s2.top()); s2.pop(); }
				}
				s1.push(x);
			}

			// Removes the element from in front of queue.
			void pop(void) {
				if (s1.size() > s2.size())
				{
					while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
				}
				s2.pop();
			}

			// Get the front element.
			int peek(void) {
				if (s1.size() > s2.size())
				{
					while (!s1.empty()) { s2.push(s1.top()); s1.pop(); }
				}
				return s2.top();
			}

			// Return whether the queue is empty.
			bool empty(void) {
				return s1.empty() && s2.empty();
			}
		};

		void Main()
		{
		}
	}
}