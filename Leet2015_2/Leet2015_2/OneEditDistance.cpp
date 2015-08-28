#include "stdafx.h"

//Given two strings S and T, determine if they are both one edit distance apart.
//Replacement cost is counted as 1

namespace Solution2
{
    namespace OneEditDistance
    {

		// To execute C++, please define "int main()"

		static unordered_map<int, vector<pair<int, int>>> map;
		int curTime = 0;


		int time()
		{
			curTime++;
			return curTime;
		}


		void put(int key, int v)
		{
			if (map.find(key) == map.end())
			{
				map[key] = vector<pair<int, int>>(1, make_pair(time(), v));
			}
			else
			{
				map[key].push_back(make_pair(time(), v));
			}
		}


		int get(int k, int t, int& result)
		{
			if (map.find(k) == map.end()) { return -1; }
			vector<pair<int, int>> entry = map[k];

			int len = entry.size();
			result = -2;

			if (entry[0].first >= t) { result = entry[0].second; }
			else if (entry[len - 1].first <= t) { result = entry[len - 1].second; }
			else
			{
				for (int i = 0; i<len; i++)
				{
					if (entry[i].first == t || (i + 1 < len && entry[i + 1].first > t))
					{
						result = entry[i].second;
						break;
					}
				}
			}
			return 0;
		}


		void  Main()
		{
			int result = -1;

			get(1, 1, result);
			cout << "get(1, 1) " << result << endl;

			put(1, 1);
			put(2, 2);
			get(1, 1, result);
			cout << "get(1, 1) " << result << endl;

			get(2, 2, result);
			cout << "get(2, 2) " << result << endl;

			put(3, 2);
			put(3, 5);
			put(3, 6);
			put(3, 6);

			get(3, 2, result);
			cout << "get(3, 2) " << result << endl;

			get(3, 0, result);
			cout << "get(3, 0) " << result << endl;

			get(3, 4, result);
			cout << "get(3, 4) " << result << endl;

			get(3, 6, result);
			cout << "get(3, 6) " << result << endl;

			get(3, 9, result);
			cout << "get(3, 9) " << result << endl;

		}
    }
}
