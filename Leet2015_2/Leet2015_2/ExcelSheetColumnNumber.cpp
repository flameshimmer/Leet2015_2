#include "stdafx.h"

//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example :
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28

namespace Solution2
{
    namespace ExcelSheetColumnNumber
    {
     
		int titleToNumber(string s) {
			int len = s.length();
			if (len == 0) { return 0; }

			int result = 0;
			for (char c : s)
			{
				result = result * 26 + (c - 'A' + 1);
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
