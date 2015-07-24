#include "stdafx.h"

//Given n non - negative integers representing an elevation map where 
//the width of each bar is 1, compute how much water it is able to trap after raining.
//
//For example,
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.

namespace Solution2
{
    namespace TrappingRainWater
    {
		namespace twoPass
		{
			int trap(vector<int>& height)
			{
				int len = height.size();
				if (len == 0) { return 0; }

				vector<int> leftMax(len, 0);
				vector<int> rightMax(len, 0);
				int maxL = 0;
				int maxR = 0;
				for (int i = 0; i < len; i++)
				{
					leftMax[i] = maxL;
					maxL = max(maxL, height[i]);

					rightMax[len - 1 - i] = maxR;
					maxR = max(maxR, height[len - 1 - i]);
				}

				int result = 0;
				for (int i = 0; i < len; i++)
				{
					result += max(min(leftMax[i], rightMax[i]) - height[i], 0);
				}
				return result;
			}
		}
   
		int trap(vector<int>& height)
		{
			int len = height.size();
			if (len == 0) { return 0; }

			int result = 0;
			int l = 0;
			int r = len - 1;
			while (l < r)
			{
				int minV = min(height[l], height[r]);
				if (minV == height[l])
				{
					l++;
					while (l < r && height[l] < minV)
					{
						result += minV - height[l];
						l++;
					}
				}
				else
				{
					r--;
					while (l < r && height[r] < minV)
					{
						result += minV - height[r];
						r--;
					}
				}
			}
			return result;
		}

        void Main()
        {
			print(trap(createVector({0,2,0})));
        }
    }
}
