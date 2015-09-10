#include "stdafx.h"

//There are a row of n houses, each house can be painted with one of the k colors.
//The cost of painting each house with a certain color is different.
//You have to paint all the houses such that no two adjacent houses have the same color.
//
//The cost of painting each house with a certain color is represented by a n x k cost matrix.
//For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... 
//
//Find the minimum cost to paint all houses.
//
//Note:
//All costs are positive integers.
//
//Follow up :
//Could you solve it in O(nk) runtime ?

namespace Solution2
{
	namespace PaintHouseII
	{

		void prepMinCost(vector<int> cost, pair<int, int>& minCost1, pair<int, int>& minCost2)
		{
			for (int i = 0; i < cost.size(); i++)
			{
				int c = cost[i];
				if (minCost1.first == INT_MAX) { minCost1.first = c; minCost1.second = i; }
				else if (minCost2.first == INT_MAX) { minCost2.first = c; minCost2.second = i; }
				else if (c > minCost1.first && c > minCost2.first) { continue; }
				else if (minCost1.first > minCost2.first) { minCost1.first = c; minCost1.second = i; }
				else { minCost2.first = c; minCost2.second = i; }
			}
			if (minCost2.first < minCost1.first) { swap(minCost1, minCost2); }
		}

		int minCostII(vector<vector<int>>& costs) {
			int houseCount = costs.size();
			if (houseCount == 0) { return 0; }
			int paintCount = costs[0].size();
			if (paintCount == 0) { return 0; }

			for (int i = 1; i < houseCount; i++)
			{
				pair<int, int> minCost1 = make_pair(INT_MAX, -1); // cost, color
				pair<int, int> minCost2 = make_pair(INT_MAX, -1); // cost, color
				prepMinCost(costs[i - 1], minCost1, minCost2);
				for (int j = 0; j < paintCount; j++)
				{
					costs[i][j] += (j == minCost1.second) ? minCost2.first : minCost1.first;
				}
			}
			int result = INT_MAX;
			for (int k = 0; k < paintCount; k++)
			{
				result = min(result, costs[houseCount - 1][k]);
			}
			return result;
		}


		namespace nkPower2{
			int minCostII(vector<vector<int>>& costs) {
				int houseCount = costs.size();
				if (houseCount == 0) { return 0; }
				int paintCount = costs[0].size();
				if (paintCount == 0) { return 0; }

				for (int i = 1; i < houseCount; i++)
				{
					for (int j = 0; j < paintCount; j++)
					{
						int preMinCost = INT_MAX;
						for (int k = 0; k < paintCount; k++)
						{
							if (k == j) { continue; }
							preMinCost = min(preMinCost, costs[i - 1][k]);
						}
						costs[i][j] += preMinCost;
					}
				}
				int result = INT_MAX;
				for (int k = 0; k < paintCount; k++)
				{
					result = min(result, costs[houseCount - 1][k]);
				}
				return result;
			}
		}



		void test1()
		{
			vector<vector<int>> costs = { { 20, 19, 11, 13, 12, 16, 16, 17, 15, 9, 5, 18 },
			{ 3, 8, 15, 17, 19, 8, 18, 3, 11, 6, 7, 12 },
			{ 15, 4, 11, 1, 18, 2, 10, 9, 3, 6, 4, 15 } };
			print(minCostII(costs));
		}

		void test2()
		{
			vector<vector<int>> costs = { {7, 6, 2} };
			print(minCostII(costs));
		}

		void test3()
		{
			vector<vector<int>> costs = { { 20, 18, 4 }, { 9, 9, 10 } };
			print(minCostII(costs));
		}

		void test4()
		{
			vector<vector<int>> costs = { { 17, 2, 17 }, { 16, 16, 5 }, { 14, 3, 19 } };
			print(minCostII(costs));
		}

		void Main()
		{
			test4();
		}
	}
}
