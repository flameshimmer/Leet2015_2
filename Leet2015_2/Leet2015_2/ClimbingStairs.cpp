#include "stdafx.h"

//You are climbing a stair case.It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps.
//In how many distinct ways can you climb to the top ?

namespace Solution2
{
    namespace ClimbingStairs
    {
		int climbStairs(int n) 
		{
			vector<int> M(n+1, 0);
			M[0] = 1;
			M[1] = 1;
			for (int i = 2; i < n+1; i++)
			{
				M[i] = M[i - 1] + M[i - 2];
			}
			return M[n];
		}

     
        void Main()
        {
         
        }
    }
}
