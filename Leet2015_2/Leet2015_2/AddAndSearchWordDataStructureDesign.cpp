#include "stdafx.h"

//Design a data structure that supports the following two operations :
//
//void addWord(word)
//bool search(word)
//search(word) can search a literal word or a regular expression string 
//containing only letters a - z or ..A.means it can represent any one letter.
//
//For example :
//
//addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

namespace Solution2
{
    namespace AddAndSearchWordDataStructureDesign
    {
		class WordDictionary {
			struct Node
			{
				bool isEnd;
				Node* children[26];
				Node()
				{
					isEnd = false;
					memset(children, NULL, sizeof(children));
				}
			};
		public:
			Node* root;
			WordDictionary() { root = new Node(); }
			// Adds a word into the data structure.
			void addWord(string word) 
			{
				Node* cur = root;
				for (char c : word)
				{
					if (cur->children[c - 'a'] == NULL)
					{
						cur->children[c - 'a'] = new Node();
					}
					cur = cur->children[c - 'a'];
				}
				cur->isEnd = true;
			}

			bool searchHelper(string& word, Node* node, int level)
			{
				if (level == word.length())
				{
					return node->isEnd;
				}

				char c = word[level];
				if (c == '.')
				{
					for (int i = 0; i < 26; i++)
					{
						if (node->children[i] != NULL && searchHelper(word, node->children[i], level + 1)) { return true; }
					}
					return false;
				}
				if (node->children[c - 'a'] == NULL) { return false; }
				return searchHelper(word, node->children[c - 'a'], level + 1);
			}


			// Returns if the word is in the data structure. A word could
			// contain the dot character '.' to represent any one letter.
			bool search(string word) 
			{
				return searchHelper(word, root, 0);
			}
		};
        
		
		void Main()
        {
			 WordDictionary wordDictionary;
			 wordDictionary.addWord("a");
			 wordDictionary.addWord("a");
			 wordDictionary.search(".");
			 wordDictionary.search("aa");
			 wordDictionary.search("a");
			 wordDictionary.search(".a");
			 wordDictionary.search("a.");
         
        }
    }
}
