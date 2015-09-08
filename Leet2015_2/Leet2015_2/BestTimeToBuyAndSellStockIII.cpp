#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most two transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

namespace Solution2
{
    namespace BestTimeToBuyAndSellStockIII
    {
     
		int maxProfit(vector<int>& prices) {
			int len = prices.size();
			if (len < 2) { return 0; }

			vector<int>P1(len, 0);
			int minVal = INT_MAX;
			int maxP1 = 0;
			vector<int> P2(len, 0);
			int maxVal = 0;
			int maxP2 = 0;

			for (int i = 0; i<len; i++)
			{
				minVal = min(minVal, prices[i]);
				maxP1 = max(maxP1, prices[i] - minVal);
				P1[i] = maxP1;

				maxVal = max(maxVal, prices[len - 1 - i]);
				maxP2 = max(maxP2, maxVal - prices[len - 1 - i]);
				P2[len - 1 - i] = maxP2;
			}

			int result = 0;
			for (int i = 0; i<len; i++)
			{
				result = max(result, P1[i] + P2[i]);
			}
			return result;
		}
     
        void Main()
        {
			vector<int> input = createVector({2, 1, 2, 0, 1});
			print(maxProfit(input));
        }
    }
}
