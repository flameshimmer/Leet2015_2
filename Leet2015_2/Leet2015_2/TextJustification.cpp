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
		
		string pipeWords(list<string>& curLine, int wordCount, int remainWidth, bool isLastLine)
		{
			string line;
			if (wordCount == 1 || isLastLine)
			{
				while (!curLine.empty())
				{
					if (line.length() > 0) { line += " ";}
					line += curLine.front();
					curLine.pop_front(); 
				}
				line += string(remainWidth, ' ');
			}
			else
			{
				while (!curLine.empty())
				{
					int extraSpace = remainWidth / (wordCount - 1);
					if (extraSpace * (wordCount - 1) < remainWidth) { extraSpace++; }
					string curWord = curLine.front();
					curLine.pop_front();
					if (line.length() == 0) { line += curWord; continue; }
					line += " ";
					for (int i = 0; i < extraSpace && remainWidth > 0; i++)
					{
						line += " ";
						remainWidth--;
					}
					line += curWord;
					wordCount--;
				}
			}
			return line;
		}

		vector<string> fullJustify(vector<string>& words, int maxWidth)
		{
			vector<string> results;
			int len = words.size();

			int remainWidth = maxWidth;
			list<string> curLine;
			int wordCount = 0;
			for (int i = 0; i < len; i++)
			{
				string w = words[i];
				int wl = w.length();
				int prefixSpace = (wordCount == 0) ? 0 : 1;
				if (remainWidth >= wl + prefixSpace)
				{
					remainWidth -= wl + prefixSpace;
					wordCount++;
					curLine.push_back(w);
				}
				else
				{
					string line = pipeWords(curLine, wordCount, remainWidth, false);
					results.push_back(line);
					wordCount = 0;
					remainWidth = maxWidth;
					i--;
				}
			}
			string line = pipeWords(curLine, wordCount, remainWidth, true);
			results.push_back(line);
			return results;
		}

		void Main()
		{		
			vector<string> input;

			input = { "Give", "me", "my", "Romeo;", "and,", "when", "he", "shall", "die,", "Take", "him", "and", "cut", "him", "out", "in", "little", "stars,", "And", "he", "will", "make", "the", "face", "of", "heaven", "so", "fine", "That", "all", "the", "world", "will", "be", "in", "love", "with", "night", "And", "pay", "no", "worship", "to", "the", "garish", "sun." };
			print(fullJustify(input, 25));
			input = { "Listen", "to", "many,", "speak", "to", "a", "few." };
			print(fullJustify(input, 6));



		
			input = { "Here", "is", "an", "example", "of", "text", "justification." };
			print(fullJustify(input, 15));


			
			input = { "Do", "all", "the", "good", "you", "can,", "By", "all", "the", "means", "you", "can,", "In", "all", "the", "ways", "you", "can,", "In", "all", "the", "places", "you", "can,", "At", "all", "the", "times", "you", "can,", "To", "all", "the", "people", "you", "can,", "As", "long", "as", "ever", "you", "can." };
			print(fullJustify(input, 26));

			
			input = { "a", "b", "c", "d", "e"};
			print(fullJustify(input, 1));


			input = { "" };
			print(fullJustify(input, 2));
		}
	}
}
