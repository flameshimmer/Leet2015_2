#include "stdafx.h"

//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

namespace Solution2
{
    namespace MaxPointsOnALine
    {
		int maxPoints(vector<Point>& points) 
		{
			int len = points.size();
			if (len < 2) { return len; }

			int result = 0;
			for (int i = 0; i < len; i++)
			{
				int dupe = 1;
				Point cur = points[i];
				unordered_map<double, int> map; // slope, count
				int verCount = 0;
				int maxNonVer = 0;
				for (int j = i + 1; j < len; j++)
				{
					Point next = points[j];
					if (cur.x == next.x && cur.y == next.y)
					{
						dupe++;
					}
					else if (cur.x == next.x)
					{
						verCount++;
					}
					else
					{
						double slope = (double)(next.y - cur.y) / (double)(next.x - cur.x);
						map[slope]++;
						maxNonVer = max(maxNonVer, map[slope]);
					}
				}
				int curResult = max(verCount, maxNonVer) + dupe;
				result = max(result, curResult);
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
