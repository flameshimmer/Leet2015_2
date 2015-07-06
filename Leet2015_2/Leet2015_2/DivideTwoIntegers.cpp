#include "stdafx.h"

//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.

namespace Solution2
{
    namespace DivideTwoIntegers
    {     
		int divide(int dividend, int divisor) {
			bool isNeg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
			long long div = dividend;
			if (div < 0) { div *= -1; }
			long long dsr = divisor;
			if (dsr < 0) { dsr *= -1; }
			
			long long result = 0;
			long long cur = 0;
			while (div >= dsr)
			{
				while (div >= (dsr << cur))  { cur++; }
				div -= dsr << cur;
				result += (long long)(1) << cur;
				cur = 0;
			}
			if (result >= INT_MAX) { return INT_MAX; }
			if (result <= INT_MIN) { return INT_MIN; }
			return (int)result;
		}

        void Main()
        {
			print(divide(INT_MIN, -1));
        }
    }
}
