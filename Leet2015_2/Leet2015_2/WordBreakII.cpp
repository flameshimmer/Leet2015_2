#include "stdafx.h"

//Given a string s and a dictionary of words dict, add spaces in s to 
//construct a sentence where each word is a valid dictionary word.
//
//Return all such possible sentences.
//
//For example, given
//s = "catsanddog",
//dict = ["cat", "cats", "and", "sand", "dog"].
//
//A solution is["cats and dog", "cat sand dog"]

namespace Solution2
{
	namespace WordBreakII
	{
		void breakWord(string& s, int len, int start, unordered_set<string>& dict, string result, vector<string>& results, vector<bool>& P)
		{
			if (start >= len)
			{
				result.pop_back();
				results.push_back(result);
			}

			for (int i = start; i < len; i++)
			{
				string cur = s.substr(start, i - start + 1);
				if (dict.find(cur) != dict.end() && P[i + 1])
				{
					int oldSize = results.size();
					breakWord(s, len, i + 1, dict, result + cur + " ", results, P);
					if (results.size() == oldSize)
					{
						P[i + 1] = false;
					}
				}
			}
		}


		vector<string> wordBreak(string s, unordered_set<string>& dict)
		{
			int len = s.length();
			vector<string> results;
			string result;
			vector<bool> P(len+1, true);
			breakWord(s, len, 0, dict, result, results, P);
			return results;
		}

		void Main()
		{
			unordered_set<string> dict = { "a", "b" };
			print(wordBreak("ab", dict));
		}
	}
}
