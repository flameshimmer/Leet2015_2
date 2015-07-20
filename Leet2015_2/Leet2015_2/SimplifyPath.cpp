#include "stdafx.h"

//Given an absolute path for a file(Unix - style), simplify it.
//
//For example,
//path = "/home/", = > "/home"
//path = "/a/./b/../../c/", = > "/c"

namespace Solution2
{
    namespace SimplifyPath
    {     
		string simplifyPath(string path) 
		{
			int len = path.length();
			if (len == 0) { return "/"; }

			string result;
			list<string> list;
			int start = 0;
			while (start < len)
			{
				while (start < len && path[start] == '/') { start++; }
				int end = start + 1;
				while (end < len && path[end] != '/') { end++; }
				end--;
				string cur = path.substr(start, end - start + 1);
				if (cur == "..")
				{
					if (!list.empty()){ list.pop_back(); }
				}
				else if (cur != "" && cur != ".")
				{
					list.push_back(cur);
				}
				start = end + 1;
			}
			while (!list.empty())
			{
				result += "/" + list.front();
				list.pop_front();
			}
			return result.length() > 0 ? result : "/";
		}
     
        void Main()
        {
			print(simplifyPath("/.."));
        }
    }
}
