#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//Design an algorithm to find the maximum profit.You may complete at most k transactions.
//
//Note:
//You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

namespace Solution2
{
	namespace BestTimeToBuyAndSellStockIV
	{
		int maxProfit(int k, vector<int>& prices) {
			int len = prices.size();
			if (len < 2) { return 0; }

			if (k > len)
			{
				int result = 0;
				for (int i = 1; i < len; i++)
				{
					result += max(0, prices[i] - prices[i - 1]);
				}
				return result;
			}

			vector<int> max_local(k+1, 0);
			vector<int> max_global(k+1, 0);

			for (int i = 1; i < len; i++)
			{
				int diff = prices[i] - prices[i - 1];
				for (int j = k; j >=1; j--)
				{
					max_local[j] = max(max_global[j - 1] + max(0, diff), max_local[j - 1]);
					max_global[j] = max(max_local[j], max_global[j]);
				}
			}
			return max_global[k];
		}

		void Main()
		{
			print(maxProfit(4, createVector({ 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 })));
			print(maxProfit(2, createVector({ 2, 1, 2, 0, 1 })));
			print(maxProfit(1, createVector({ 1, 2 })));
		}
	}
}
