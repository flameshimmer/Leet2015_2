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
//	 The read function will only be called once for each test case.

namespace Solution2
{
    namespace ReadNCharactersGivenRead4
    {
		int read4(char *buf){ return 0; }
		/**
		* @param buf Destination buffer
		* @param n   Maximum number of characters to read
		* @return    The number of characters read
		*/
		int read(char *buf, int n) {
			int remain = n;
			int readCount = 0;
			char temp[4];
			
			while (remain > 0)
			{
				readCount = read4(temp);
				for (int i = 0; i < readCount && remain > 0; i++)
				{
					*buf = temp[i];
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
