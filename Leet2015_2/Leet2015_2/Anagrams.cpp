#include "stdafx.h"

//Given an array of strings, return all groups of strings that are anagrams.
//
//Note: All inputs will be in lower - case.


namespace Solution2
{
    namespace Anagrams
    {
     
		vector<string> anagrams(vector<string>& strs) {
			vector<string> result;
			int len = strs.size();
			if (len < 1) { return result; }
			
			unordered_map<string, vector<string>> map;
			for (string s : strs)
			{
				string key = s;
				sort(key.begin(), key.end());
				map[key].emplace_back(s);
			}

			for (auto p : map)
			{
				vector<string> group = p.second;
				if (group.size() > 1)
				{
					for (string s : group) { result.push_back(s); }
				}
			}
			return result;
		}
     
     
        void Main()
        {
			vector<string> input = { "", "" };
			print(anagrams(input));
        }
    }
}
