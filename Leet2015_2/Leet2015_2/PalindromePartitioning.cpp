#include "stdafx.h"

//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//For example, given s = "aab",
//Return
//
//[
//	["aa", "b"],
//	["a", "a", "b"]
//]

namespace Solution2
{
    namespace PalindromePartitioning
    {
		bool isPalindrome(string& s, int start, int end)
		{
			while (start < end)
			{
				if (s[start] != s[end]) { return false; }
				start++;
				end--;
			}
			return true;
		}


		void partition(string& s, int len, int start, vector<string>& result, vector<vector<string>>& results)
		{
			if (start == len) 
			{
				results.push_back(result);
				return;
			}

			for (int i = start; i < len; i++)
			{
				if (isPalindrome(s, start, i))
				{
					result.push_back(s.substr(start, i-start + 1));
					partition(s, len, i+1, result, results);
					result.pop_back();
				}			
			}
		}

		vector<vector<string>> partition(string s) 
		{
			vector<vector<string>> results;
			int len = s.length();
			if (len == 0) { return results; }
			vector<string> result;
			partition(s, len, 0, result, results);
			return results;
		}
     
     
        void Main()
        {
			print(partition("aab"));
        }
    }
}
