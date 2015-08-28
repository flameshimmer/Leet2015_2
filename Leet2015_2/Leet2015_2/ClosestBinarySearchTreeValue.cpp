#include "stdafx.h"


//Given a non - empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
//Note:
//Given target value is a floating point.
//You are guaranteed to have only one unique value in the BST that is closest to the target.
//

namespace Solution2
{
	namespace ClosestBinarySearchTreeValue
	{
		int closestValue(TreeNode* root, double target) {
			bool seenSmaller = false;
			bool seenLarger = false;

			int result = root->val;
			TreeNode* cur = root;
			while (cur)
			{
				if (seenSmaller && seenLarger) { break; }
				if (cur->val == target) { result = target; break; }
				else if (cur->val < target)
				{
					seenSmaller = true;
					if (target - cur->val < abs(result -target))
					{
						result = cur->val;
					}
					cur = cur->right;
				}
				else
				{
					seenLarger = true;
					if (cur->val - target < abs(result - target))
					{
						result = cur->val;
					}
					cur = cur->left;
				}
			}
			return result;
		}

		void Main()
		{
			vector<string> treeData = { "41", "37", "44", "24", "39", "42", "48", "1", "35", "38", "40", "null", "43", "46", "49", "0", "2", "30", "36", "null", "null", "null", "null", "null", "null", "45", "47", "null", "null", "null", "null", "null", "4", "29", "32", "null", "null", "null", "null", "null", "null", "3", "9", "26", "null", "31", "34", "null", "null", "7", "11", "25", "27", "null", "null", "33", "null", "6", "8", "10", "16", "null", "null", "null", "28", "null", "null", "5", "null", "null", "null", "null", "null", "15", "19", "null", "null", "null", "null", "12", "null", "18", "20", "null", "13", "17", "null", "null", "22", "null", "14", "null", "null", "21", "23" };
			treeData = { "1", "2", "3", "null", "null", "null", "null" };
			printTree(treeData);
		}
	}
}