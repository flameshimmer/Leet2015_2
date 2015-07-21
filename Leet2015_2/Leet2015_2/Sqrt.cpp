#include "stdafx.h"

//Implement int sqrt(int x).
//
//Compute and return the square root of x.

namespace Solution2
{
    namespace Sqrt
    {
     
		int mySqrt(int x) 
		{
			long long start = 0;
			long long end = x / 2 + 1;
			while (start <= end)
			{
				long long mid = start + (end - start) / 2;
				long long val = mid * mid;
				if (val == x)
				{
					return mid;
				}
				else if (val < x)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			return end;
		}
        void Main()
        {
         
        }
    }
}
