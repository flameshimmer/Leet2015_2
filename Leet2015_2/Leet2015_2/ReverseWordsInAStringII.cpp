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

			// Trim begin
			int start = 0;
			while (start < len && s[start] == ' ')
			{
				start++;
			}
			s.erase(s.begin(), s.begin() + start);
			
			// Trim end
			int end = 0;
			while (end < len  && s[len-1-end] == ' ')
			{
				end++;
			}
			s.erase(s.end() - end, s.end());

			reverse(s, 0, len - 1);
			start = 0;
			end = -1;
			while (start < len)
			{
				while (start < len && s[start] == ' ')
				{
					start++;
				}
				if (start - end - 1 > 1)
				{
					s.replace(s.begin() + end, s.begin() + start-1, 1, ' ');
				}
				end = start + 1;
				while (end < len && s[end] != ' ')
				{
					end++;
				}
				end--;
				reverse(s, start, end);
				start = end + 1;
			}
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
