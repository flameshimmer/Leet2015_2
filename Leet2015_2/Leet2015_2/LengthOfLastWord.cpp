#include "stdafx.h"

//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	  For example,
//	  Given s = "Hello World",
//	  return 5.

namespace Solution2
{
    namespace LengthOfLastWord
    {
     
		int lengthOfLastWord(string s) {
			int len = s.length();
			if (len == 0) { return 0; }
			int start = len-1;
			int end = len - 1;
			
			while (start >= 0 && s[start] == ' '){ start--; }
			end = start;
			while (start >= 0 && s[start] != ' '){ start--; }

			return end - start;
		}
     
     
        void Main()
        {
         
        }
    }
}
