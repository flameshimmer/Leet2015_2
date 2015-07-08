#include "stdafx.h"

//Given n non - negative integers representing the histogram's bar
//height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//Given height = [2, 1, 5, 6, 2, 3],
//return 10.

namespace Solution2
{
    namespace LargestRectangleInHistogram
    {
     
		int largestRectangleArea(vector<int>& height) 
		{
			stack<int> s;
			height.push_back(0);

			int result = 0;
			for (int i = 0; i < height.size(); i++)
			{
				if (s.empty() || height[s.top()] <= height[i])
				{
					s.push(i);
				}
				else
				{
					int tmp = s.top();
					s.pop();
					int startIndex = s.empty() ? -1 : s.top();
					result = max(result, height[tmp] * (i - startIndex -1));
					i--;
				}
			}
			return result;
		}
     
     
        void Main()
        {
			print(largestRectangleArea(createVector({ 2, 1, 2 })));
        }
    }
}
