#include "stdafx.h"


//Given an integer n, count the total number of digit 1 appearing in all non - negative integers less than or equal to n.
//
//For example :
//Given n = 13,
//Return 6, because digit 1 occurred in the following numbers : 1, 10, 11, 12, 13.
//
//Hint:
//
//Beware of overflow.


namespace Solution2
{
	namespace NumberOfDigitOne
	{
		
		
		int countDigitOne(int n) {
			if (n < 0) { return 0; }
			int result = 0;
			int scale = 1;
			int factor = 0;
			int x = n;

			while (x)
			{
				int lastDigit = x % 10;
				int extra = scale;
				if (lastDigit == 0) { extra = 0; }
				else if (lastDigit == 1) { extra = 1 + n%scale; }

				result += lastDigit * factor + extra;
				factor = factor * 10 + scale;
				scale *= 10;
				x /= 10;
			}
			return result;

		}


		void Main()
		{
			print(countDigitOne(13));
		}
	}
}