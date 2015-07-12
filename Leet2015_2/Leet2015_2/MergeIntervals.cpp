#include "stdafx.h"

//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
//Given[1, 3], [2, 6], [8, 10], [15, 18],
//return[1, 6], [8, 10], [15, 18].

namespace Solution2
{
    namespace MergeIntervals
    {

		static bool compFunc(Interval a, Interval b)
		{
			return a.start < b.start;
		}
		bool intersect(Interval a, Interval b)
		{
			bool notIntersect = a.end < b.start || b.end < a.start;
			return !notIntersect;
		}

		Interval merge(Interval a, Interval b)
		{
			return Interval(min(a.start, b.start), max(a.end, b.end));
		}

		vector<Interval> merge(vector<Interval>& intervals) 
		{
			vector<Interval> result;
			int len = intervals.size();
			if (len == 0) { return result; }
			
			sort(intervals.begin(), intervals.end(), compFunc);
			result.push_back(intervals[0]);

			for (int i = 1; i < len; i++)
			{
				Interval cur = intervals[i];				
				while (!result.empty() && intersect(cur, result.back()))
				{
					Interval back = result.back();
					result.pop_back();
					cur = merge(cur, back);
				}
				result.push_back(cur);
			}			
			return result;
		}
    
        void Main()
        {
			vector<Interval> input = {Interval(1, 4), Interval(1, 4)};
			print(merge(input));
        }
    }
}
