#include "stdafx.h"

//Implement pow(x, n).

namespace Solution2
{
    namespace Pow
    {
     
		double myPow(double x, int n) {			
			long long n2 = n;
			bool isNeg = false;
			if (n2 < 0) { isNeg = true; n2 *= -1; }
			
			long long m = 1;
			double curVal = x;
			double result = 1;
			while (n2)
			{
				while (m * 2 < n2)
				{
					curVal *= curVal;
					m *= 2;
				}
				n2 -= m;
				result *= curVal;
				m = 1;
				curVal = x;
			}
			if (isNeg) { result = 1.0 / result; }
			return result;
		}
     
     
        void Main()
        {
			print(myPow(34.00515, -3));
        }
    }
}
