#include "stdafx.h"

//Given an array of words and a length L, format the text such that each line 
//has exactly L characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words 
//as you can in each line.Pad extra spaces ' ' when necessary so that each line 
//has exactly L characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the 
//number of spaces on a line do not divide evenly between words, the empty slots
//on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is
//inserted between words.
//
//For example,
//words: ["This", "is", "an", "example", "of", "text", "justification."]
//   L : 16.
//
//Return the formatted lines as :
//[
//	"This    is    an",
//	"example  of text",
//	"justification.  "
//]
//Note : Each word is guaranteed not to exceed L in length.

namespace Solution2
{
	namespace TextJustification
	{
		string pipeWords(vector<string>& words, int start, int end, int remainWidth)
		{
			if (start > end) { return string(remainWidth, ' '); }
			string line = words[start];
			int extra = 0;
			int gapCount = end - start;
			for (int i = start + 1; i <= end; i++)
			{
				if (start == end || end == words.size() - 1) { extra = 0; }
				else
				{
					extra = (remainWidth + gapCount - 1) / gapCount;
					gapCount--;
					remainWidth -= extra;
				}
				line += string(extra + 1, ' ') + words[i];
			}
			if (remainWidth) { line += string(remainWidth, ' '); }
			return line;
		}

		vector<string> fullJustify(vector<string>& words, int maxWidth)
		{
			vector<string> result;
			int len = words.size();

			int start = 0;
			while (start < len)
			{
				int end = start;
				int remainWidth = maxWidth;
				while (end < len && words[end].length() + (start == end ? 0 : 1) <= remainWidth)
				{
					remainWidth -= words[end].length() + (start == end ? 0 : 1);
					end++;
				}
				end--;
				result.push_back(pipeWords(words, start, end, remainWidth));
				start = end + 1;
			}
			return result;
		}

		void Main()
		{		
			vector<string> input;


			input = { "Here", "is", "an", "example", "of", "text", "justification." };
			print(fullJustify(input, 16));

			input = { "Give", "me", "my", "Romeo;", "and,", "when", "he", "shall", "die,", "Take", "him", "and", "cut", "him", "out", "in", "little", "stars,", "And", "he", "will", "make", "the", "face", "of", "heaven", "so", "fine", "That", "all", "the", "world", "will", "be", "in", "love", "with", "night", "And", "pay", "no", "worship", "to", "the", "garish", "sun." };
			print(fullJustify(input, 25));
			input = { "Listen", "to", "many,", "speak", "to", "a", "few." };
			print(fullJustify(input, 6));

			
			input = { "Do", "all", "the", "good", "you", "can,", "By", "all", "the", "means", "you", "can,", "In", "all", "the", "ways", "you", "can,", "In", "all", "the", "places", "you", "can,", "At", "all", "the", "times", "you", "can,", "To", "all", "the", "people", "you", "can,", "As", "long", "as", "ever", "you", "can." };
			print(fullJustify(input, 26));

			
			input = { "a", "b", "c", "d", "e"};
			print(fullJustify(input, 1));


			input = { "" };
			print(fullJustify(input, 2));
		}
	}
}
