#include "stdafx.h"

//You are given a string, S, and a list of words, L, that are all of 
//the same length.Find all starting indices of substring(s) in S that
//is a concatenation of each word in L exactly once and without any 
//intervening characters.
//
//For example, given:
//S : "barfoothefoobarman"
//L : ["foo", "bar"]
//
//	You should return the indices : [0, 9].
//	(order does not matter).

namespace Solution2
{
    namespace SubstringWithConcatenationOfAllWords
    {
		vector<int> findSubstring(string s, vector<string>& words) 
		{
			vector<int> result;
			int lens = s.length();
			if (lens == 0) { return result; }
			int sizew = words.size();
			if (sizew == 0) { for (int i = 0; i < lens; i++) { result.push_back(i); } return result; }
			int lenw = words[0].length();

			map<string, int> toBeFound;
			for (string w : words) { toBeFound[w]++; }


			for (int i = 0; i <= lens - sizew * lenw; i++)
			{
				map<string, int> hasFound;
				int foundCount = 0;
				int start = i;
				while (start <= lens - lenw)
				{
					string cur = s.substr(start, lenw);
					if (toBeFound.find(cur) != toBeFound.end() && hasFound[cur] < toBeFound[cur]) { hasFound[cur]++; foundCount++; }
					else{ break; }

					if (foundCount == sizew) { result.push_back(i); break; }
					start += lenw;
				}
			}
			return result;
		}
     
        void Main()
        {
			vector<string> dict;


			dict = { "a", "a" };
			print(findSubstring("aaa", dict));

			dict = { "foo", "bar", "the" };
			print(findSubstring("barfoofoobarthefoobarman", dict));

			dict = { "foo", "bar" };
			print(findSubstring("barfoothefoobarman", dict));
        }
    }
}
