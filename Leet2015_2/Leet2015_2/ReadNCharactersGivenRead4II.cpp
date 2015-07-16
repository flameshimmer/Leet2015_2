#include "stdafx.h"

//The API : int read4(char *buf) reads 4 characters at a time from a file.
//
//The return value is the actual number of characters read.For example, 
//it returns 3 if there is only 3 characters left in the file.
//
//By using the read4 API, implement the function int read(char *buf, int n) 
//that reads n characters from the file.
//
//Note :
//	 The read function may be called multiple times.

namespace Solution2
{
    namespace ReadNCharactersGivenRead4II
    {
     
		// Forward declaration of the read4 API.
		int read4(char *buf){ return 0; }
		/**
		* @param buf Destination buffer
		* @param n   Maximum number of characters to read
		* @return    The number of characters read
		*/
		
		char temp[4];
		int tempIndex = 4;
		int readCount = 0;

		int read(char *buf, int n) 
		{
			int remain = n;
			for (; tempIndex < readCount && remain > 0; tempIndex++)
			{
				*buf = temp[tempIndex];
				buf++;
				remain--;
			}

			while (remain)
			{
				readCount = read4(temp);
				for (tempIndex = 0; tempIndex < readCount && remain > 0; tempIndex++)
				{
					*buf = temp[tempIndex];
					buf++;
					remain--;
				}
				if (readCount < 4) { break; }
			}
			return n - remain;
		}
     
        void Main()
        {
         
        }
    }
}
