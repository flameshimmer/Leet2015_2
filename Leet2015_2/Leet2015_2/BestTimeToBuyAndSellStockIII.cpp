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

			vector<int> first(len);
			int minVal = INT_MAX;
			int maxP1 = 0;
			vector<int> second(len);
			int maxVal = 0;
			int maxP2 = 0;

			for (int i = 0; i < len; i++)
			{
				maxP1 = max(maxP1, max(0, prices[i] - minVal));
				first[i] = maxP1;
				minVal = min(minVal, prices[i]);

				maxP2 = max(maxP2, max(0, maxVal - prices[len - 1 - i]));
				second[len - 1 - i] = maxP2;
				maxVal = max(maxVal, prices[len - 1 - i]);
			}

			int result = 0;
			for (int i = 0; i < len; i++)
			{
				result = max(result, first[i] + second[i]);
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
