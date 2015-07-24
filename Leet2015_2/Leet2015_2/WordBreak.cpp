#include "stdafx.h"

//Given a string s and a dictionary of words dict, determine if s can be segmented 
//into a space - separated sequence of one or more dictionary words.
//
//For example, given
//s = "leetcode",
//dict = ["leet", "code"].
//
//Return true because "leetcode" can be segmented as "leet code".


namespace Solution2
{
    namespace WordBreak
    {

     
		bool wordBreak(string s, unordered_set<string>& dict) {
			int lens = s.length();
			if (lens == 0) { return false; }
			int len = dict.size();
			if (len == 0) { return false; }

			vector<bool> M(lens + 1, false);
			M[0] = true;
			for (int i = 1; i < lens+1; i++)
			{
				for (int j = 0; j < i; j++)
				{
					if (M[j] && dict.find(s.substr(j, i - j)) != dict.end())
					{
						M[i] = true; 
						break;
					}
				}
			}
			return M[lens];
		}
     
        void Main()
        {
			unordered_set<string> dict = { "a" };
		

			print(wordBreak("a", dict));
        }
    }
}
