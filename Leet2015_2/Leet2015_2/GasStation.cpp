#include "stdafx.h"

//There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
//
//You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i
//to its next station(i + 1).You begin the journey with an empty tank at one of the gas stations.
//
//Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
//
//Note:
//The solution is guaranteed to be unique.

namespace Solution2
{
    namespace GasStation
    {
     
		int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
		{
			int len = gas.size();
			int start = 0;
			int end = 0;
			int sum = 0;
			int count = 0;

			while (start < len)
			{
				sum += gas[end%len] - cost[end%len];
				count++;
				while (sum < 0 && start <= end && start < len)
				{
					sum -= gas[start] - cost[start];
					start++;
					count--;
				}
				end++;
				if (count == len) { return start; }
			}
			return -1;
		}
     
     
        void Main()
        {
			print(canCompleteCircuit(createVector({ 1, 2, 3, 3 }), createVector({ 2, 1, 5, 1 })));
        }
    }
}
