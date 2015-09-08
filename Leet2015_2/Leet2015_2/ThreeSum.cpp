#include "stdafx.h"
using namespace std;

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ? Find all unique triplets 
// in the array which gives the sum of zero.

//Note :
//	 Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ≤ b ≤ c)
//	 The solution set must not contain duplicate triplets.
//	 For example, given array S = { -1 0 1 2 - 1 - 4 },
//-4, -1, -1, 0, 1, 2
//	 A solution set is :
//  (-1, 0, 1)
//	(-1, -1, 2)


namespace Solution2
{
    namespace ThreeSum
    {
		vector<vector<int>> threeSum(vector<int>& nums) 
		{
			vector<vector<int>> results;
			int len = nums.size();
			if (len < 3) { return results; }

			sort(nums.begin(), nums.end());

			for (int i = 0; i < len; i++)
			{
				int target = 0 - nums[i];
				int start = i+1;
				int end = len - 1;
				while (start < end)
				{
					int sum = nums[start] + nums[end];
					if (sum == target)
					{
						vector<int> result;
						result.push_back(nums[i]);
						result.push_back(nums[start]);
						result.push_back(nums[end]);
						results.push_back(result);
						start++;
						while (start < len && nums[start] == nums[start - 1]) { start++; }
					}
					else if (sum < target)
					{
						start++;
						while (start < len && nums[start] == nums[start - 1]) { start++; }
					}
					else
					{
						end--;
						while (end < len && nums[end] == nums[end + 1]) { end--; }
					}
				}
				while (i + 1 < len && nums[i] == nums[i + 1])
				{
					i++;
				}
			}
			return results;
		}
     
		namespace hashTable
		{
			vector<vector<int>> threeSum(vector<int>& nums) {
				vector<vector<int>> results;
				int len = nums.size();
				if (len < 3) { return results; }

				unordered_map<int, pair<int, int>> map;
				vector<int> result;
				for (int i = 0; i<len; i++)
				{
					map.clear();
					for (int j = i + 1; j<len; j++)
					{
						if (map.find(nums[j]) != map.end())
						{
							pair<int, int> p = map[nums[j]];
							result.push_back(p.first);
							result.push_back(p.second);
							result.push_back(nums[j]);
							results.push_back(result);
							result.clear();
						}
						else
						{
							int sum = nums[i] + nums[j];
							map[-sum] = make_pair(nums[i], nums[j]);
						}
					}
				}
				return results;
			}
		}
     
     
        void Main()
        {
			print(hashTable::threeSum(createVector({ -1, 0, 1, 2, -1, -4 })));
			//print(threeSum(createVector({ 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 })));
        }
    }
}
