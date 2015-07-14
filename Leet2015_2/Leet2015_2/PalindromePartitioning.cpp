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


		void partition(string& s, int start, vector<string>& result, vector<vector<string>>& results)
		{
			if (start == s.length()) 
			{
				results.push_back(result);
				return;
			}


		}

		vector<vector<string>> partition(string s) 
		{
			vector<vector<string>> results;
			int len = s.length();
			if (len == 0) { return results; }
			vector<string> result;
			vector<vector<bool>> P()

		}
     
     
        void Main()
        {
         
        }
    }
}
