#include "stdafx.h"

//There are N children standing in a line.Each child is assigned a rating value.
//
//You are giving candies to these children subjected to the following requirements :
//
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//What is the minimum candies you must give ?

namespace Solution2
{
    namespace Candy
    {     
		int candy(vector<int>& ratings) 
		{
			int len = ratings.size();
			if (len == 0) { return 0; }

			vector<int> candy(len, 1);
			for (int i = 1; i < len; i++)
			{
				if (ratings[i] > ratings[i - 1])
				{
					candy[i] = candy[i - 1] + 1;
				}
			}

			int total = candy[len-1];
			for (int i = len - 2; i >= 0; i--)
			{
				if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
				{
					candy[i] = candy[i + 1] + 1;
				}
				total += candy[i];
			}
			return total;
		}     
     
        void Main()
        {
         
        }
    }
}
