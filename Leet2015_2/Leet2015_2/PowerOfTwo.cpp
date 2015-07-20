#include "stdafx.h"

//Given an integer, write a function to determine if it is a power of two.
//
//Credits:
//Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
//

namespace Solution2
{
	namespace PowerOfTwo
	{
		bool isPowerOfTwo(int n) 
		{
			if (n <= 0) { return false; }
			return (n & n - 1) == 0;
		}

		void Main()
		{
		}
	}
}