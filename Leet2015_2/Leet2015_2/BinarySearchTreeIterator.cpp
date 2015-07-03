#include "stdafx.h"

//Implement an iterator over a binary search tree(BST).Your iterator will be initialized with the root node of a BST.
//
//Calling next() will return the next smallest number in the BST.
//
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

namespace Solution2
{
    namespace BinarySearchTreeIterator
    {
     
		class BSTIterator {
		private:
			stack<TreeNode*> s;
			TreeNode* cur;
		public:			
			BSTIterator(TreeNode *root) {
				cur = root;
			}

			/** @return whether we have a next smallest number */
			bool hasNext() {
				return (cur != NULL || !s.empty());
			}

			/** @return the next smallest number */
			int next() {
				int result;
				while (!s.empty() || cur != NULL)
				{
					if (cur)
					{
						s.push(cur);
						cur = cur->left;
					}
					else
					{
						TreeNode* top = s.top();
						result = top->val;
						s.pop();
						cur = top->right;
						break;
					}
				}
				return result;
			}
		};
     
     
        void Main()
        {
			TreeNode* root = new TreeNode(1);

			BSTIterator i = BSTIterator(root);
			while (i.hasNext()) cout << i.next();
        }
    }
}
