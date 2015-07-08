#include "stdafx.h"

//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given[3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
namespace Solution2
{
    namespace LargestNumber
    {
		
		static bool CompFunc(int a, int b)
		{
			string stra = to_string(a);
			string strb = to_string(b);
			return stra + strb > strb + stra;
		}
		
		string largestNumber(vector<int>& nums) 
		{
			sort(nums.begin(), nums.end(), CompFunc);
			string result;
			for (int val : nums)
			{
				if (result.size() == 0 && val == 0) { continue; }
				result += to_string(val);
			}
			if (result.empty()) { result = "0"; }
			return result;
		}
     
        void Main()
        {
			print(largestNumber(createVector({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 })));
        }
    }
}
