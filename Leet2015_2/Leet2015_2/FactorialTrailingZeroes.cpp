#include "stdafx.h"

//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.

namespace Solution2
{
    namespace FactorialTrailingZeroes
    {
     
		int trailingZeroes(int n) 
		{
			if (n < 0) { return -1; }
			int count = 0;
			long long x = 5;
			while (n >= x)
			{
				count += n / x;
				x *= 5;
			}
			return count;
		}
     
     
        void Main()
        {
         
        }
    }
}
