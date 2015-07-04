#include "stdafx.h"

//The count - and - say sequence is the sequence of integers beginning as follows :
//1, 11, 21, 1211, 111221, ...
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth sequence.
//
//Note: The sequence of integers will be represented as a string.
namespace Solution2
{
    namespace CountAndSay
    {   
		string countAndSay(int n) 
		{
			string input = "1";

			for (int i = 0; i < n-1; i++)
			{
				int len = input.length();
				int j = 0;
				string newInput = "";
				while (j < len)
				{
					int count = 1;
					while (j+1 < len && input[j] == input[j + 1]) { count++; j++; }
					newInput += to_string(count) + input[j];
					j++;
				}
				input = newInput;
			}
			return input;
		}

        void Main()
        {
			print(countAndSay(1));
        }
    }
}
