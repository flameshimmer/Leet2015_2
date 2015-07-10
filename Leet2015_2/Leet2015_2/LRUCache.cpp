#include "stdafx.h"

//Design and implement a data structure for Least Recently Used(LRU) cache.It should support the following operations : get and set.
//
//get(key) - Get the value(will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present.When the cache reached its capacity, 
//it should invalidate the least recently used item before inserting a new item.

namespace Solution2
{
	namespace LRUCacheEntry
    {     
		namespace tooSlow{
			class LRUCache{
			private:
				int m_cap;
				list<int> m_keyList;
				unordered_map<int, pair<list<int>::iterator, int>> m_map;

				void moveToFront(int key)
				{
					m_keyList.erase(m_map[key].first);
					m_keyList.push_front(key);
					m_map[key].first = m_keyList.begin();
				}

			public:
				LRUCache(int capacity) {
					m_cap = capacity;
				}

				int get(int key) {
					if (m_map.find(key) == m_map.end()) { return -1; }
					moveToFront(key);
					return m_map[key].second;
				}

				void set(int key, int value) {
					if (m_map.find(key) != m_map.end())
					{
						m_map[key].second = value;
						moveToFront(key);
					}
					else
					{
						m_keyList.push_front(key);
						m_map[key] = make_pair(m_keyList.begin(), value);

						if (m_keyList.size() > m_cap)
						{
							m_map.erase(m_keyList.back());
							m_keyList.pop_back();
						}
					}
				}
			};
		}

		class LRUCache{
		private:
			struct Node
			{
				int key;
				int val;
				Node* next;
				Node* prev;
				Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL){}
			};

			int m_cap;
			int m_len;
			Node* m_head;
			unordered_map<int, Node*> m_map;

			void moveToFront(int key)
			{
				Node* target = m_map[key];
				target->prev->next = target->next;
				if (target->next){ target->next->prev = target->prev; }				

				target->next = m_head->next;
				if (m_head->next){ m_head->next->prev = target->next; }				
				
				m_head->next = target;
				target->prev = m_head;
			}

		public:
			LRUCache(int capacity) {
				m_cap = capacity;
				m_head = new Node(INT_MIN, INT_MIN);
			}

			int get(int key) {
				if (m_map.find(key) == m_map.end()) { return -1; }
				moveToFront(key);
				return m_map[key]->val;
			}

			void set(int key, int value) {
				if (m_map.find(key) != m_map.end())
				{
					m_map[key]->val = value;
					moveToFront(key);
				}
				else
				{
					Node* newNode = new Node(key, value);
					newNode->next = m_head->next;
					if (m_head->next){ m_head->next->prev = newNode; }					

					m_head->next = newNode;
					newNode->prev = m_head;
					
					m_map[key] = newNode;
					m_len++;
					if (m_len > m_cap)
					{
						Node* tail = m_head;
						while (tail->next) { tail = tail->next; }
						Node* temp = tail->prev;
						temp->next = NULL;						
						delete tail;
						m_len--;
					}
				}
			}
		};


        void Main()
        {
			LRUCache cache(1);
			cache.set(2, 1);
			//cache.get(1);

			cache.set(2, 2);
			cache.get(2);
			cache.set(1, 1);
			cache.set(4, 1);
			cache.get(2);

			//cache.set(1, 1);
			//cache.set(2, 2);
			//cache.set(3, 3);
			//cache.set(4, 4);
			//cache.get(4);
			//cache.get(3);
			//cache.get(2);
			//cache.get(1);
			//cache.set(5, 5);
			//cache.get(1);
			//cache.get(2);
			//cache.get(3);
			//cache.get(4);
			//cache.get(5);
        }
    }
}
