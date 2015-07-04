#include "stdafx.h"

//A message containing letters from A - Z is being encoded to numbers using the following mapping :
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//Given an encoded message containing digits, determine the total number of ways to decode it.
//
//For example,
//Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
//The number of ways decoding "12" is 2.

namespace Solution2
{
    namespace DecodeWays
    {

		int numDecodings(string s) {
			int len = s.size();
			if (len == 0) { return 0; }
			vector<int> M(len + 1, 0);
			M[0] = 1;
			M[1] = (s[0] == '0') ? 0 : 1;

			for (int i = 2; i < len + 1; i++)
			{
				if (s[i - 1] != '0') { M[i] = M[i - 1]; }
				if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6)) { M[i] += M[i - 2]; }
			}
			return M[len];
		}
     
        void Main()
        {
			print(numDecodings("26"));
        }
    }
}
