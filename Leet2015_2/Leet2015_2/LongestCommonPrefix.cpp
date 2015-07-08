#include "stdafx.h"

//Write a function to find the longest common prefix string amongst an array of strings.
// "aa", "ab", "abc"
namespace Solution2
{
    namespace LongestCommonPrefix
    {
     
		string longestCommonPrefix(vector<string>& strs) 
		{
			string result = "";
			int len = strs.size();
			if (len == 0) { return result; }

			for (int i = 0; i < strs[0].size(); i++)
			{
				char c = strs[0][i];
				for (int j = 1; j < len; j++)
				{
					if (strs[j][i] != c) { return result; }
				}
				result.push_back(c);
			}
			return result;
		}
     
     
        void Main()
        {
			vector<string> input = { "" };
			print(longestCommonPrefix(input));
        }
    }
}
