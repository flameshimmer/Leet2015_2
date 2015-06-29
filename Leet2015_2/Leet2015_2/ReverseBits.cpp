#include "stdafx.h"

//Reverse bits of a given 32 bits unsigned integer.

//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//
//Follow up :
//If this function is called many times, how would you optimize it ?

namespace Solution2
{
    namespace ReverseBits
    {
     
		uint32_t reverseBits(uint32_t n) 
		{
			uint32_t start = 0;
			uint32_t end = 31;
			while (start < end)
			{
				if (((n >> start) & 1) ^ ((n >> end) & 1))
				{
					n ^= (1 << start) | (1 << end);
				}
				start++;
				end--;
			}
			return n;
		}
     
		namespace other
		{
			uint32_t reverseBits(uint32_t n)
			{
				uint32_t result = 0;
				int i = 0;
				while (i < 32)
				{
					if (n & (1 << i))
					{
						result += 1 << (31 - i);
					}
					i++;
				}
				return result;
			}
		}
     
        void Main()
        {
			uint32_t input = 43261596;
			input = 4294967295;
			uint32_t result = reverseBits(input);
			printBits(input);
			printBits(result);
			print(result);
        }
    }
}
