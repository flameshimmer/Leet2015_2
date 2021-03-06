#include "stdafx.h"

//You are a professional robber planning to rob houses along a street.
//Each house has a certain amount of money stashed, the only constraint
//stopping you from robbing each of them is that adjacent houses have 
//security system connected and it will automatically contact the police 
//if two adjacent houses were broken into on the same night.
//
//Given a list of non - negative integers representing the amount of money
//of each house, determine the maximum amount of money you can rob tonight
//without alerting the police.

namespace Solution2
{
    namespace HouseRobber
    {
     
		int rob(vector<int>& nums) 
		{
			int len = nums.size();
			if (len == 0) { return 0; }
			vector<int> M(len + 1, 0);
			M[1] = nums[0];
			for (int i = 2; i < len+1; i++)
			{
				M[i] = max(M[i - 1], M[i - 2] + nums[i - 1]);
			}
			return M[len];
		}
     
     
        void Main()
        {
         
        }
    }
}
