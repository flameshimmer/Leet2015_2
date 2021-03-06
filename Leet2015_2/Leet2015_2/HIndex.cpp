#include "stdafx.h"

//Given an array of citations(each citation is a non - negative integer) of a researcher, write a function to compute the researcher's h-index.
//
//According to the definition of h - index on Wikipedia : "A scientist has index h if h of his/her N papers have at least h citations each, 
//and the other N − h papers have no more than h citations each."
//
//For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
//Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h - index is 3.
//
//Note : If there are several possible values for h, the maximum one is taken as the h - index.

namespace Solution2
{
	namespace HIndex
	{
		int hIndex(vector<int>& cit) {
			int len = cit.size();
			int result = 0;

			vector<int> count(len + 1, 0);
			for (int c : cit)
			{
				count[min(c, len)] ++;
			}
			for (int i = len; i >= 0; i--)
			{
				result += count[i];
				if (result >= i) { return i; }
			}
			return result;
		}

		namespace nLogn
		{
			int hIndex(vector<int>& cit) {
				int len = cit.size();
				if (len == 0) { return 0; }

				sort(cit.begin(), cit.end());

				for (int i = 0; i < len; i++)
				{
					if (cit[i] >= len - i) { return len - i; }
				}
				return 0;
			}
		}

		void Main()
		{
		}
	}
}
