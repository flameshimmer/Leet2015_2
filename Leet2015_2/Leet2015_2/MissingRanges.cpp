#include "stdafx.h"

//Given a sorted integer array where the range of elements are[lower, upper] inclusive, return its missing ranges.
//
//For example, given[0, 1, 3, 50, 75], lower = 0 and upper = 99, return["2", "4->49", "51->74", "76->99"].
//
namespace Solution2
{
    namespace MissingRanges
    {
     
		vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
		{			
			nums.insert(nums.begin(), lower - 1); 
			nums.push_back(upper + 1); 
			vector<string> result;
			for (int i = 1; i < nums.size(); i++)
			{
				if (nums[i] - nums[i - 1] > 2)
				{
					result.push_back(to_string(nums[i - 1] + 1) + "->" + to_string(nums[i] - 1));
				}
				else if (nums[i] - nums[i - 1] == 2)
				{
					result.push_back(to_string(nums[i] - 1));
				}
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
