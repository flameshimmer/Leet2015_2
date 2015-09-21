#include "stdafx.h"

//There is a new alien language which uses the latin alphabet.However, the order among letters are unknown to you.
//You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this 
//new language.Derive the order of letters in this language.
//
//For example,
//Given the following words in dictionary,
//
//[
//	"wrt",
//	"wrf",
//	"er",
//	"ett",
//	"rftt"
//]
//The correct order is : "wertf".
//
//Note :
//	 You may assume all letters are in lowercase.
//	 If the order is invalid, return an empty string.
//	 There may be multiple valid order of letters, return any one of them is fine.

namespace Solution2
{
	namespace AlienDictionary
	{

		string alienOrder(vector<string>& words) 
		{
			string result;
			int len = words.size();
			if (len == 0) { return result; }

			unordered_map<char, int> inDegree;
			for (string w : words) 
			{
				for (char c : w)
				{
					inDegree[c] = 0;
				}
			}

			vector<pair<char, char>> pairs;
			for (int i = 0; i < len - 1; i++)
			{
				string cur = words[i];
				string next = words[i + 1];
				int lenCur = cur.size();
				int lenNext = next.size();
				int k = 0;
				while (k < lenCur && k < lenNext && cur[k] == next[k]) { k++; }
				if (k < lenCur && k < lenNext)
				{
					pairs.push_back(make_pair(cur[k], next[k]));
					inDegree[next[k]]++;
				}
			}

			stack<char> s;
			for (auto p : inDegree) { if (p.second == 0) { s.push(p.first); } }

			while (!s.empty())
			{
				char c = s.top();
				s.pop();
				result.push_back(c);
				for (auto p : pairs)
				{
					if (p.first == c) { inDegree[p.second]--; if (inDegree[p.second] == 0) { s.push(p.second); } }
				}
			}

			for (auto p : inDegree) { if (p.second != 0){ return ""; } }
			return result;
		}

		void Main()
		{
			vector<string> words;

			words = { "zy", "zx" };
			print(alienOrder(words));

			words = { "ri", "xz", "qxf", "jhsguaw", "dztqrbwbm", "dhdqfb", "jdv", "fcgfsilnb", "ooby" };
			print(alienOrder(words));

			words = { "z", "z" };
			print(alienOrder(words));

			words = { "wrt", "wrf", "er", "ett", "rftt" };
			print(alienOrder(words));

			words = { "aac", "aabb", "aaba" };
			print(alienOrder(words));

			words = { "z", "x"};
			print(alienOrder(words));

		}
	}
}
