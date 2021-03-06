#include "stdafx.h"

//A city's skyline is the outer contour of the silhouette formed by all the buildings in 
//that city when viewed from a distance. Now suppose you are given the locations and height
//of all the buildings as shown on a cityscape photo (Figure A), write a program to output 
//the skyline formed by these buildings collectively (Figure B).
//
//Buildings  Skyline Contour
//The geometric information of each building is represented by a triplet of integers[Li, Ri, Hi],
//where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively,
//and Hi is its height.It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0.
//You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
//
//For instance, the dimensions of all buildings in Figure A are recorded as :
//[[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]] .
//
//The output is a list of "key points" (red dots in Figure B) in the format of
//[[x1, y1], [x2, y2], [x3, y3], ...] that uniquely defines a skyline.A key point is the left
//endpoint of a horizontal line segment.Note that the last key point, where the rightmost building
//ends, is merely used to mark the termination of the skyline, and always has zero height.Also, the 
//ground in between any two adjacent buildings should be considered part of the skyline contour.
//
//For instance, the skyline in Figure B should be represented as : 
//[[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]].
//
//Notes :
//
//	  The number of buildings in any input list is guaranteed to be in the range[0, 10000].
//	  The input list is already sorted in ascending order by the left x position Li.
//	  The output list must be sorted by the x position.
//	  There must be no consecutive horizontal lines of equal height in the output skyline.
//	  For instance, 
//	  
//[...[2 3], [4 5], [7 5], [11 5], [12 7]...] 
//	  is not acceptable; 
//	  the three lines of height 5 should be merged into one in the final output as such : 
//[...[2 3], [4 5], [12 7], ...]

namespace Solution2
{
	namespace TheSkylineProblem
	{
		namespace logged{
			vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
				vector<pair<int, int>> result;
				int len = buildings.size();
				int cur = 0;
				int curX = 0;
				int curH = -1;
				priority_queue<pair<int, int>> liveBlg;

				while (cur < len || !liveBlg.empty())
				{
					print("\n\ncur building indext is: " + to_string(cur));

					curX = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;

					if (liveBlg.empty()) { print("live building empty! curX is the curBuilding's left: " + to_string(buildings[cur][0])); }
					else { print("live building NOT empty! curX is the tallest building's right: " + to_string(liveBlg.top().second)); }

					if (cur >= len || buildings[cur][0] > curX)
					{
						if (cur >= len) { cout << "No new builing to process. draining the ones in the live\n"; }
						else { print("curX(" + to_string(curX) + ") is SMALLER than the current building's left (" + to_string(buildings[cur][0]) + ")"); }
						while (!liveBlg.empty() && liveBlg.top().second <= curX)
						{
							print("CurBuilding's left(" + to_string(curX) + ") is equal or larger than the tallest right building right (" + to_string(liveBlg.top().second) + "), poping live building's top.");

							liveBlg.pop();
						}
					}
					else
					{
						print("curX(" + to_string(curX) + ") is EQUAL or LARGER than the current building's left (" + to_string(buildings[cur][0]) + ")");
						curX = buildings[cur][0];
						print("setting curX to curBuilding's left: " + to_string(buildings[cur][0]));
						while (cur < len && buildings[cur][0] == curX)
						{
							print("pushing building (height, right) == (" + to_string(buildings[cur][2]) + "," + to_string(buildings[cur][1]) + ")");
							liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
							cur++;
							print("Increment cur process building to: " + to_string(cur));
						}
					}

					curH = liveBlg.empty() ? 0 : liveBlg.top().first;
					if (liveBlg.empty()) { cout << "live building is empty. curH is 0\n"; }
					else { print("curH is: " + to_string(curH)); }

					if (result.empty() || result.back().second != curH)
					{
						if (result.empty())
						{
							cout << "No skyline point yet\n";
						}
						else { print("height is different than the last skyline point. old is: " + to_string(result.back().second) + ", new is: " + to_string(curH)); }

						result.push_back(make_pair(curX, curH));
						print("Adding skyline point(x, y) == (" + to_string(curX) + ", " + to_string(curH) + ")");
					}
					else if (!result.empty() && result.back().second == curH) { print("height is the same as the last skyline point. which is: " + to_string(result.back().second)); }
				}
				return result;
			}
		}

		vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) 
		{
			vector<pair<int, int>> results;
			int len = buildings.size();
			if (len == 0) { return results; }
			int cur = 0;
			priority_queue<pair<int, int>>live;

			while (cur < len || !live.empty())
			{
				int curX = live.empty() ? buildings[cur][0] : live.top().second;
				if (cur >= len || buildings[cur][0] > curX)
				{
					while (!live.empty() && live.top().second <= curX)
					{
						live.pop();
					}
				}
				else
				{
					curX = buildings[cur][0];
					while (cur < len && buildings[cur][0] == curX)
					{
						live.push(make_pair(buildings[cur][2], buildings[cur][1]));
						cur++;
					}
				}
				int curH = live.empty() ? 0 : live.top().first;
				if (results.empty() || curH != results.back().second)
				{
					results.push_back(make_pair(curX, curH));
				}
			}
			return results;
		}

		void Main()
		{
			// [[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]
			vector<vector<int>> input = { { 2, 9, 10 }, { 3, 7, 15 }, { 5, 12, 12 }, { 15, 20, 10 }, { 19, 24, 8 } };
			print(getSkyline(input));
			cout << "[[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]\n";
		}
	}
}