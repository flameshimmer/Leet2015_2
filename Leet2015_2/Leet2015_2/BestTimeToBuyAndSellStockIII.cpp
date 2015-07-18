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

			vector<int> smallestBefore(len);
			vector<int> largestAfter(len);
			int minVal = INT_MAX;
			int maxVal = 0;
			for (int i = 0; i < len; i++)
			{
				smallestBefore[i] = minVal;
				minVal = min(minVal, prices[i]);

				largestAfter[len - 1 - i] = maxVal;
				maxVal = max(maxVal, prices[len-1-i]);
			}

			int result = 0;
			int leftProfit = 0;
			int rightProfit = 0;
			for (int i = 0; i < len; i++)
			{
				leftProfit = max(leftProfit, max(0, prices[i] - smallestBefore[i]));
				rightProfit = max(0, largestAfter[i] - prices[i]);
				result = max(result, leftProfit + rightProfit);
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
