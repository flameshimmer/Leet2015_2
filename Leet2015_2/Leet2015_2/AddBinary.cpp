#include "stdafx.h"

//Given two binary strings, return their sum(also a binary string).
//
//For example,
//a = "11"
//b = "1"
//Return "100".


namespace Solution2
{
    namespace AddBinary
    {
		string addBinary(string a, string b) 
		{
			int ia = a.length()-1;
			int ib = b.length()-1;
			int carry = 0;
			string result;
			while (ia >= 0 || ib >= 0 || carry > 0)
			{
				int val1 = (ia >= 0) ? (a[ia] - '0') : 0;
				int val2 = (ib >= 0) ? (b[ib] - '0') : 0;
				result.insert(result.begin(), '0' + ((val1 + val2 + carry) % 2));
				carry = (val1 + val2 + carry) / 2;
				ia--;
				ib--;
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
