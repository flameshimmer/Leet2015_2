#include "stdafx.h"

//Given a complete binary tree, count the number of nodes.
//
//Definition of a complete binary tree from Wikipedia :
//In a complete binary tree every level, except possibly the last, is completely filled, 
//and all nodes in the last level are as far left as possible.It can have between 1 and 2h nodes inclusive at the last level h.
/*
		    1
		 /     \
	    2       3
	  /   \    / \
	 4     5  6   7
	/ \   / 
   8   9 10  

*/
namespace Solution2
{
    namespace CountCompleteTreeNodes
    {
		int countNodes(TreeNode* root) 
		{
			if (!root) { return 0; }
			TreeNode* cur = root;
			int lh = 0;
			while (cur) { lh++; cur = cur->left;}
			
			cur = root;
			int rh = 0;
			while (cur) { rh++; cur = cur->right;}

			if (lh == rh) { return pow(2, lh) - 1; }
			else { return 1 + countNodes(root->left) + countNodes(root->right); }
		}
     
        void Main()
        {
         
        }
    }
}
