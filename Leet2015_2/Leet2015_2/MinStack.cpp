#include "stdafx.h"

//Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//push(x) --Push element x onto stack.
//pop() --Removes the element on top of the stack.
//top() --Get the top element.
//getMin() --Retrieve the minimum element in the stack.

namespace Solution2
{
    namespace MinStack
    {
     
		class MinStack {
			vector<int> stack;
			vector<int> minStack;
		public:
			void push(int x) {
				stack.push_back(x);
				if (minStack.empty() || minStack.back() >= x)
				{
					minStack.push_back(x);
				}
			}

			void pop() {
				if (minStack.back() == stack.back()) { minStack.pop_back(); }
				stack.pop_back();
			}

			int top() {
				return stack.back();
			}

			int getMin() {
				return minStack.back();
			}
		};
     
     
        void Main()
        {
         
        }
    }
}
