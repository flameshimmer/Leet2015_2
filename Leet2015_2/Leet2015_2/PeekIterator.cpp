#include "stdafx.h"

//Given an Iterator class interface with methods : next() and hasNext(), design and implement a PeekingIterator that support the peek() operation 
//-- it essentially peek() at the element that will be returned by the next call to next().
//
//Here is an example.Assume that the iterator is initialized to the beginning of the list : [1, 2, 3].
//
//Call next() gets you 1, the first element in the list.
//
//Now you call peek() and it returns 2, the next element.Calling next() after that still return 2.
//
//You call next() the final time and it returns 3, the last element.Calling hasNext() after that should return false.
//
//Show Hint
//Follow up : How would you extend your design to be generic and work with all types, not just integer ?

namespace Solution2
{
	namespace PeekIterator
	{

		// Below is the interface for Iterator, which is already defined for you.
		// **DO NOT** modify the interface for Iterator.
		class Iterator {
			struct Data;
			Data* data;
		public:
			Iterator(const vector<int>& nums);
			Iterator(const Iterator& iter);
			virtual ~Iterator();
			// Returns the next element in the iteration.
			int next();
			// Returns true if the iteration has more elements.
			bool hasNext() const;
		};


		class PeekingIterator : public Iterator {
		private:
			bool peeked;
			int peekedElm;
		public:
			PeekingIterator(const vector<int>& nums) : Iterator(nums) {
				peeked = false;
			}

			// Returns the next element in the iteration without advancing the iterator.
			int peek() {
				peekedElm = peeked ? peekedElm : Iterator::next();
				peeked = true;
				return peekedElm;
			}

			// hasNext() and next() should behave the same as in the Iterator interface.
			// Override them if needed.
			int next() {
				int result = peeked ? peekedElm : Iterator::next();
				peeked = false;
				return result;
			}

			bool hasNext() const {
				return peeked || Iterator::hasNext();
			}
		};


		void Main()
		{

		}
	}
}
