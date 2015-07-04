#include "stdafx.h"

//Given n non - negative integers a1, a2, ..., an, where each represents
//a point at coordinate(i, ai).n vertical lines are drawn such that the 
//two endpoints of line i is at(i, ai) and(i, 0).Find two lines, which 
//together with x - axis forms a container, such that the container 
//contains the most water.
//
//Note: You may not slant the container.

namespace Solution2
{
    namespace ContainerWithMostWater
    {
     
		int maxArea(vector<int>& height) 
		{
			int len = height.size();
			if (len < 2) { return 0; }

			int start = 0; 
			int end = len - 1;
			int result = 0;
			while (start < end)
			{
				int h = min(height[start], height[end]);
				int curResult = (end - start) * h;
				result = max(curResult, result);

				while (start < end && height[start] <= h) { start++; }
				while (start < end && height[end] <= h) { end--; }
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
