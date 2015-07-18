#include "stdafx.h"

//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction(ie, buy one and sell one share of the stock),
//design an algorithm to find the maximum profit.

namespace Solution2
{
    namespace BestTimeToBuyAndSellStock
    {
          
		int maxProfit(vector<int>& prices) {
			int len = prices.size();
			if (len < 2) { return 0; }

			vector<int> minPrices(len);
			int minVal = INT_MAX;
			for (int i = 0; i < len; i++)
			{
				minVal = min(minVal, prices[i]);
				minPrices[i] = minVal;
			}

			int result = 0;
			int maxVal = INT_MIN;
			for (int i = len - 1; i >= 0; i--)
			{
				maxVal = max(maxVal, prices[i]);
				result = max(result, maxVal - minPrices[i]);
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
