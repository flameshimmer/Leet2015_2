#include "stdafx.h"

//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//	  Example2 : x = -123, return -321

namespace Solution2
{
    namespace ReverseInteger
    {	
		int reverse(int x) {
			long long result = 0;
			while (x != 0)
			{
				result = result * 10 + x % 10;
				x /= 10;
			}

			if (result > INT_MAX) { return 0; }
			if (result < INT_MIN) { return 0; }
			return (int)result;
		}
     
     
        void Main()
        {
			print(reverse(123));
			print(reverse(-123));
			print(reverse(INT_MAX));
			print(reverse(INT_MIN));
			print(reverse(0));
        }
    }
}
