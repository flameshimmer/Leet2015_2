#include "stdafx.h"

//Given two strings s and t, determine if they are isomorphic.
//
//Two strings are isomorphic if the characters in s can be replaced to get t.
//
//All occurrences of a character must be replaced with another character while
//preserving the order of characters.No two characters may map to the same 
//character but a character may map to itself.
//
//For example,
//Given "egg", "add", return true.
//
//Given "foo", "bar", return false.
//
//Given "paper", "title", return true.
//
//Note:
//You may assume both s and t have the same length.

namespace Solution2
{
    namespace IsomorphicStrings
    {
     
		bool isIsomorphic(string s, string t) {
			int lens = s.length();
			int lent = t.length();
			if (lens != lent)  { return false; }
			
			char map[256] = { 0 };
			char mapTo[256] = { 0 };
			for (int i = 0; i < lens; i++)
			{
				if ((map[s[i]] == NULL || map[s[i]] == t[i]) && (!mapTo[t[i]] || mapTo[t[i]] == s[i]))
				{
					map[s[i]] = t[i];
					mapTo[t[i]] = s[i];
				}
				else
				{
					return false;
				}
			}
			return true;
		}
     
     
        void Main()
        {
         
        }
    }
}
