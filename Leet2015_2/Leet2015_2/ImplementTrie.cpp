#include "stdafx.h"

//Implement a trie with insert, search, and startsWith methods.
//
//Note:
//You may assume that all inputs are consist of lowercase letters a - z.

namespace Solution2
{
    namespace ImplementTrie
    {
		class TrieNode {
		public:
			bool isEnd;
			TrieNode* children[26];
			// Initialize your data structure here.
			TrieNode() {
				isEnd = false;
				memset(children, NULL, sizeof(children));
			}
		};

		class Trie {
		public:
			Trie() {
				root = new TrieNode();
			}

			// Inserts a word into the trie.
			void insert(string word) {
				TrieNode* cur = root;

				for (char c : word)
				{
					if (cur->children[c - 'a'] == NULL)
					{
						cur->children[c - 'a'] = new TrieNode();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			// Returns if the word is in the trie.
			bool search(string word) {
				TrieNode* cur = root;
				for (char c : word)
				{
					if (cur->children[c - 'a'] == NULL) { return false; }
					cur = cur->children[c - 'a'];
				}
				return cur->isEnd;
			}

			// Returns if there is any word in the trie
			// that starts with the given prefix.
			bool startsWith(string prefix) {
				TrieNode* cur = root;
				for (char c : prefix)
				{
					if (cur->children[c - 'a'] == NULL) { return false; }
					cur = cur->children[c - 'a'];
				}
				return true;
			}

		private:
			TrieNode* root;
		};
     
     
     
        void Main()
        {
         
        }
    }
}
