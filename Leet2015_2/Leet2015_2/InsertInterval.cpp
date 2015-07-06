#include "stdafx.h"

//Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
//Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
//
//Example 2 :
//Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
//
//This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
namespace Solution2
{
    namespace InsertInterval
    {     
		vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
		{
			vector<Interval> result;
			int len = intervals.size();
			if (len == 0) { result.push_back(newInterval); return result; }

			int i = 0;
			while (i < len && intervals[i].end < newInterval.start)
			{
				result.push_back(intervals[i]);
				i++;
			}

			int start = newInterval.start;
			if (i < len) { start = min(start, intervals[i].start); }
			while (i < len && intervals[i].start <= newInterval.end) { i++; }

			int end = newInterval.end;
			if (i - 1 >= 0) { end = max(end, intervals[i - 1].end); }
			result.push_back(Interval(start, end));
			
			while (i < len)
			{
				result.push_back(intervals[i]);
				i++;
			}			
			return result;
		}
     
        void Main()
        {
			vector<Interval> intervals = { { 1, 5 } };
			Interval newInterval = { 2, 3 };
			print(insert(intervals, newInterval));
        }
    }
}
