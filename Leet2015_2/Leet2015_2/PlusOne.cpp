#include "stdafx.h"

//Given a non - negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list

namespace Solution2
{
    namespace PlusOne
    {
     
		vector<int> plusOne(vector<int>& digits) 
		{
			vector<int> result;
			int len = digits.size();
			if (len == 0) { return result; }

			int carry = 1;
			int index = len - 1;
			while (index >= 0 || carry > 0)
			{
				int sum = carry + (index >= 0 ? digits[index] : 0);
				result.insert(result.begin(), sum % 10);
				carry = sum / 10;
				index--;
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
