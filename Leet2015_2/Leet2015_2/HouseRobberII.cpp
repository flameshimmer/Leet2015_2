#include "stdafx.h"

//Note: This is an extension of House Robber.
//
//After robbing those houses on that street, the thief has found himself a new 
//place for his thievery so that he will not get too much attention.This time, 
//all houses at this place are arranged in a circle.That means the first house 
//is the neighbor of the last one.Meanwhile, the security system for these houses
//remain the same as for those in the previous street.
//
//Given a list of non - negative integers representing the amount of money of 
//each house, determine the maximum amount of money you can rob tonight without 
//alerting the police.

namespace Solution2
{
    namespace HouseRobberII
    {
     
		int rob(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }
			if (len == 1) { return nums[0]; }

			vector<int>M(len + 1, 0);
			M[1] = nums[0];
			for (int i = 2; i < len; i++)
			{
				M[i] = max(M[i - 1], M[i - 2] + nums[i - 1]);
			}
			int op1 = M[len - 1];

			fill(M.begin(), M.end(), 0);
			for (int i = 2; i < len + 1; i++)
			{
				M[i] = max(M[i - 1], M[i - 2] + nums[i - 1]);
			}
			int op2 = M[len];
			return max(op1, op2);
		}
     
        void Main()
        {
			print(rob(createVector({1})));
        }
    }
}
