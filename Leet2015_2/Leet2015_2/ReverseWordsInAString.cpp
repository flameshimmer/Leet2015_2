#include "stdafx.h"

//Given an input string, reverse the string word by word.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Update(2015 - 02 - 12) :
//For C programmers : Try to solve it in - place in O(1) space.

namespace Solution2
{
    namespace ReverseWordsInAString
    {
     
		void reverse(string& s, int start, int end)
		{
			int len = s.length();
			while (start < end && start < len && end < len)
			{
				char c = s[start];
				s[start] = s[end];
				s[end] = c;
				start++;
				end--;
			}
		}

		void reverseWords(string &s) {
			string s2 = "";
			int len = s.length();
			if (len == 0) { return; }

			reverse(s, 0, len - 1);
			int start = 0;
			int end = -1;
			while (start < len)
			{
				while (start < len && s[start] == ' ') { start++; }
				end = start + 1;

				while (end < len && s[end] != ' ') { end++; }
				end--;

				reverse(s, start, end);
				string newStr = s.substr(start, end - start + 1);
				if (newStr.length() > 0) { s2 += newStr + " "; }
				start = end + 1;
			}
			if (s2.size() > 0)
			{
				s2.pop_back();
			}			
			s = s2;
		}
     
     
        void Main()
        {
			string input;

			input = "the sky is blue";
			print(input);
			reverseWords(input);
			print(input);    

			input = " 1";
			printWithSpace(input);
			reverseWords(input);
			printWithSpace(input);
        }
    }
}
