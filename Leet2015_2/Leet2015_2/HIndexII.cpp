#include "stdafx.h"

//Follow up for H - Index: What if the citations array is sorted in ascending order ? Could you optimize your algorithm ?
//
//Hint :
//
//	 Expected runtime complexity is in O(log n) and the input is sorted.

namespace Solution2
{
	namespace HIndexII
	{
		int hIndex(vector<int>& cit) {
			int len = cit.size();
			if (len == 0) { return 0; }

			int start = 0;
			int end = len - 1;

			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (cit[mid] < len - mid)
				{
					start = mid + 1;
				}
				else { end = mid - 1; }
			}
			return len - start;
		}

		void Main()
		{
		}
	}
}
