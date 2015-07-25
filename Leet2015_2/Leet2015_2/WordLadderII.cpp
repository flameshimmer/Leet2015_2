#include "stdafx.h"

//Given two words(start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that :
//
//Only one letter can be changed at a time
//Each intermediate word must exist in the dictionary
//For example,
//
//Given :
//	  start = "hit"
//	  end = "cog"
//	  dict = ["hot", "dot", "dog", "lot", "log"]
//	  Return
//	  [
//		  ["hit", "hot", "dot", "dog", "cog"],
//		  ["hit", "hot", "lot", "log", "cog"]
//	  ]
//Note:
//All words have the same length.
//All words contain only lowercase alphabetic characters.

namespace Solution2
{
    namespace WordLadderII
    {
		vector<string> findDistOneWords(string word, unordered_set<string>& dict)
		{
			vector<string> result;
			for (int i = 0; i < word.length(); i++)
			{
				char tmp = word[i];
				for (int j = 0; j < 26; j++)
				{
					char c = j + 'a';
					if (c == tmp) { continue; }
					word[i] = c;
					if (dict.find(word) != dict.end())
					{
						result.push_back(word);
					}
				}
				word[i] = tmp;
			}
			return result;
		}

		void constructPath(string s, unordered_map<string, pair<string, int>>& map, string start, vector<string>& result)
		{
			vector<string> path;
			string cur = s;
			while (cur != "")
			{
				path.push_back(cur);
				cur = map[cur].first;
			}
			bool insertFront = false;
			if (path[path.size() - 1] == start) {insertFront = true; }
			
			if (insertFront){ for (string p : path) { result.insert(result.begin(), p); } }
			else {for (string p : path) { result.push_back(p); }}
		}

		vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
			vector<vector<string>> results;
			dict.insert(start);
			dict.insert(end);
			unordered_set<string> s1;
			s1.insert(start);
			unordered_set<string> s2;
			s2.insert(end);			
			unordered_set<string> temp;
			unordered_map<string, pair<string, int>> map; // word, (parent, level)
			map[start] = make_pair("", INT_MAX);
			map[end] = make_pair("", INT_MAX);
			bool met = false;
			vector<string> result;
			int level = 1;
			while (!s1.empty() && !s2.empty() && !met)
			{
				if (s1.size() > s2.size()) { swap(s1, s2); }

				for (string s : s1)
				{
					level++;
					vector<string> children = findDistOneWords(s, dict);
					for (string child : children)
					{						
						if (s2.find(child) != s2.end())
						{
							result.clear();
							constructPath(s, map, start, result);
							constructPath(child, map, start, result);
							print(result);
							results.push_back(result);
							met = true;
						}
						if (map.find(child) == map.end() || level <= map[child].second)
						{
							map[child].first = s;
							map[child].second = level;
						}
						
						if (s1.find(child) == s1.end())
						{
							temp.insert(child);
						}						
					}
					dict.erase(s);
				}
				swap(s1, temp);
			}
			return results;
		}
     
        void Main()
        {
			unordered_set<string> dict = { "hot", "cog", "dot", "dog", "hit", "lot", "log" };
			print(findLadders("hit", "cog", dict));

			unordered_set<string> dict2 = { "a", "b", "c" };
			print(findLadders("a", "c", dict2));
        }
    }
}
