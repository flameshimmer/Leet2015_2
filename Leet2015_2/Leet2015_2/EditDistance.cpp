#include "stdafx.h"

//Given two words word1 and word2, find the minimum number of steps required 
//to convert word1 to word2. (each operation is counted as 1 step.)
//
//You have the following 3 operations permitted on a word :
//
//a) Insert a character
//b) Delete a character
//c) Replace a character

namespace Solution2
{
    namespace EditDistance
    {
		int minDistance(string word1, string word2) 
		{
			int len1 = word1.length();
			int len2 = word2.length();

			if (len1 == 0 || len2 == 0) { return len1 == 0 ? len2 : len1; }

			vector<int>M(len2 + 1, 0);
			for (int i = 1; i < len2 + 1; i++)
			{
				M[i] = i;
			}

			for (int i = 1; i < len1 + 1; i++)
			{
				int lastPrev = i - 1;
				M[0] = i;
				for (int j = 1; j < len2 + 1; j++)
				{
					int temp = M[j];
					if (word1[i - 1] == word2[j - 1])
					{
						M[j] = lastPrev;
					}
					else
					{
						M[j] = min(M[j] +1, min(M[j-1] + 1, lastPrev + 1));
					}
					lastPrev = temp;
				}
			}
			return M[len2];
		}
     
        void Main()
        {
			print(minDistance("a", "b"));
			print(minDistance("a", "a"));
        }
    }
}
