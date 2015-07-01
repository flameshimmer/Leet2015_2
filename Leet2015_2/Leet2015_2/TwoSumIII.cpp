#include "stdafx.h"

//Design and implement a TwoSum class.It should support the following operations : add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value.
//
//For example,
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false
//

namespace Solution2
{
    namespace TwoSumIII
    {
		
		class TwoSum {
		public:
			unordered_map<int, int> map;
			void add(int number) {
				map[number]++;
			}

			bool find(int value) {
				auto it = map.begin();
				while (it != map.end())
				{
					auto it2 = map.find(value - it->first);
					if (it2 != map.end() && (it2 != it || it->second > 1))
					{
						return true;
					}
					it++;
				}
				return false;
			}
		};
     
     
        void Main()
        {
			TwoSum twoSum;
			twoSum.add(3);
			twoSum.add(2);
			twoSum.add(1);
			twoSum.find(1);
			twoSum.find(2);
			twoSum.find(3);
			twoSum.find(4);
        }
    }
}
