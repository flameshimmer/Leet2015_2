#include "stdafx.h"

//Given a range[m, n] where 0 <= m <= n <= 2147483647, 
//return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range[5, 7], you should return 4.

namespace Solution2
{
    namespace BitwiseAndOfNumbersRange
    {
     
		int rangeBitwiseAnd(int m, int n) {
			int diff = n - m;
			if (m == n) { return m; }
			int mask = 0;
			while (diff)
			{
				mask = (mask << 1) | 1;
				diff >>= 1;
			}
			return m & (~mask);
		}

		namespace other
		{
			int rangeBitwiseAnd(int m, int n) 
			{
				int mask = ~0; 
				int count = 0;
				while ((m&mask<<count) ^ (n&mask<<count))
				{
					count++;
				}
				return m & (mask << count);
			}
		}
     
     
        void Main()
        {
			print(rangeBitwiseAnd(5, 7));
        }
    }
}
