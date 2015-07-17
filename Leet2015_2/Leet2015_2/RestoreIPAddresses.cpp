#include "stdafx.h"

//Given a string containing only digits, restore it by returning 
//all possible valid IP address combinations.
//
//For example :
//Given "25525511135",
//
//return["255.255.11.135", "255.255.111.35"]. (Order does not matter)

namespace Solution2
{
    namespace RestoreIPAddresses
    {     
		bool isValid(string s)
		{
			int val = 0;
			for (int i = 0; i < s.length(); i++)
			{
				val = val * 10 + s[i] - '0';
			}
			if (val > 255) { return false; }
			return true;
		}
		void getIp(string s, int len, int start, int remainLevel, string result, vector<string>&results)
		{
			if (start == len)
			{
				if (remainLevel == 0)
				{
					result.pop_back();
					results.push_back(result);
				}
				return;
			}

			int remainChar = len - start;
			if (remainChar < remainLevel || remainChar > remainLevel * 3) { return; }

			int possibleLen = s[start] == '0' ? 1 : 3;
			for (int j = 1; j <= possibleLen; j++)
			{
				string sub = s.substr(start, j);
				if (isValid(sub))
				{
					getIp(s, len, start + j, remainLevel - 1, result + sub + ".", results);
				}
			}			
		}

		vector<string> restoreIpAddresses(string s) {
			vector<string> results;

			int len = s.length();
			if (len < 4 || len > 12) { return results; }

			string result;
			getIp(s, len, 0, 4, result, results);
			return results;
		}
     
        void Main()
        {
			print(restoreIpAddresses("25525511135"));
        }
    }
}
