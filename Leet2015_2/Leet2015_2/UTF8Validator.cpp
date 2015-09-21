#include "stdafx.h"

//After given clearly definition of UTF - 8 format.ex: 1 - byte : 0b0xxxxxxx 2 - bytes : ....Asked to write a function to validate whether the input is valid UTF - 8. 
//Input will be string / byte array, output should be yes / no.

namespace Solution2
{
	namespace UTF8Validator
	{
/*
		bool isValidUTF8(vector<unsigned char> s)
		{
			int size = 0;
			for (unsigned char c : s)
			{
				if (size == 0)
				{
					if ((c >> 7 == 0)) { size = 0; }
					else if ((c >> 5) == 0b110) { size = 1; }
					else if ((c >> 4) == 0b1110) { size = 2; }
					else if ((c >> 3) == 0b11110) { size = 3; }
					else {return false; }
				}
				else
				{
					if ((c >> 6) != 0b10) return false;
					size--;
				}
			}
			return size == 0;
		}
*/

		void Main()
		{

		}
	}
}
