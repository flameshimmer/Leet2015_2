#include "stdafx.h"

//Given an input string, reverse the string word by word.A word is defined as a sequence of non - space characters.
//
//The input string does not contain leading or trailing spaces and the words are always separated by a single space.
//
//For example,
//Given s = "the sky is blue",
//return "blue is sky the".
//
//Could you do it in - place without allocating extra space ?

namespace Solution2
{
    namespace ReverseWordsInAStringII
    {
		void reverse(string& s, int start, int end)
		{
			int len = s.length();
			while (start < end && end < len)
			{
				char temp = s[start];
				s[start] = s[end];
				s[end] = temp;
				start++;
				end--;
			}
		}

		void reverseWords(string &s) 
		{
			int len = s.length();
			if (len == 0) { return; }

			int start = 0;
			while (start < len && s[start] == ' '){ start++; }
			s.erase(s.begin(), s.begin() + start);

			int end = 0;
			while (end < s.size() && s[len - 1 - end] == ' '){ end++; }
			s.erase(s.end() - end, s.end());

			start = 0;
			while (start < s.size())
			{
				end = start + 1;
				while (end < s.size() && s[end] != ' '){ end++; }
				end--;
				reverse(s, start, end);
				start = end + 1;
				if (start >= s.size()) { break; }

				end = start + 1;
				while (end < s.size() && s[end] == ' ') { end++; }
				end--;
				if (start != end)
				{
					s.replace(s.begin() + start, s.begin() + end, 1, ' ');
				}
				start = end + 1;
			}
			reverse(s, 0, s.length() - 1);
		}
     
        void Main()
        {
			string input;

			input = "a b";
			print(input);
			reverseWords(input);
			print(input);

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
