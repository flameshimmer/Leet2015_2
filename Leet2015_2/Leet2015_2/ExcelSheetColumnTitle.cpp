#include "stdafx.h"

//Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
//For example :
//
//1->A
//2->B
//3->C
//...
//26->Z
//27->AA
//28->AB
//

namespace Solution2
{
    namespace ExcelSheetColumnTitle
    {     
		string convertToTitle(int n) 
		{
			string result = "";
			while (n)
			{
				n--;
				char c = n % 26 + 'A';
				result.insert(result.begin(), c);
				n = n / 26;
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
