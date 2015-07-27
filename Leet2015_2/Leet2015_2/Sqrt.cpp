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

		namespace NewtonsMethod
		{
			int mySqrt(int x)
			{
				double r = 1;
				do
				{
					r = r - r / 2 + x / r / 2;
				} while (abs(x - r*r) >= 1);
				return int(r);
			}
		}
        void Main()
        {
         
        }
    }
}
