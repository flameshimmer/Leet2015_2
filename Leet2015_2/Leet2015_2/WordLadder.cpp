#include "stdafx.h"

//Given two words(beginWord and endWord), and a dictionary, find the length
//of shortest transformation sequence from beginWord to endWord, such that :
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given :
//	  start = "hit"
//	  end = "cog"
//	  dict = ["hot", "dot", "dog", "lot", "log"]
//	  As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//	  return its length 5.
//
//  Note :
//	   Return 0 if there is no such transformation sequence.
//	   All words have the same length.
//	   All words contain only lowercase alphabetic characters.

namespace Solution2
{
    namespace WordLadder
    {   
		vector<string> getDistanceOneWords(string word, unordered_set<string>& dict)
		{
			vector<string> results;
			for (int i = 0; i < word.length(); i++)
			{
				string cur = word;
				char t = word[i];
				for (int j = 0; j < 26; j++)
				{				
					char c = 'a' + j;
					if (c == t) { continue; }
					word[i] = c;
					if (dict.find(word) != dict.end()){ results.push_back(word); }
				}
				word[i] = t;
			}
			return results;
		}


		int ladderLength(string beginWord, string endWord, unordered_set<string>& dict) 
		{
			dict.insert(beginWord);
			dict.insert(endWord);

			unordered_set<string>s1;
			s1.insert(beginWord);
			unordered_set<string>s2;
			s2.insert(endWord);
			int result = 1;
			unordered_set<string> temp;

			while (!s1.empty() && !s2.empty())
			{
				if (s1.size() > s2.size()) { swap(s1, s2); }
				result++;
				temp.clear();
				for (string s : s1)
				{
					vector<string> children = getDistanceOneWords(s, dict);
					for (string child : children)
					{
						if (s2.find(child) != s2.end()) { return result; }
						temp.insert(child);
					}
					dict.erase(s);
				}
				swap(s1, temp);
			}
			return 0;
		}
     
        void Main()
        {
			unordered_set<string> dict = { "hot", "dog", "dot" };
			print(ladderLength("hot", "dog", dict));
			
			unordered_set<string> dict2 = { "a", "b", "c" };
			print(ladderLength("a", "c", dict2));

        }
    }
}
