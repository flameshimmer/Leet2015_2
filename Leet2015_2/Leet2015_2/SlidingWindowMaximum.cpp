#include "stdafx.h"

//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.
//
//For example,
//Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.
//
/*
//		Window position					Max
//-----------------------------------------------
	   [1  3  -1] -3  5  3  6  7        3
		1 [3  -1  -3] 5  3  6  7		3
		1  3[ -1  -3  5] 3  6  7		5
		1  3  -1[ -3  5  3] 6  7		5
		1  3  -1  -3 [5  3  6] 7		6
		1  3  -1  -3  5[ 3  6  7]		7
*/
//Therefore, return the max sliding window as[3, 3, 5, 5, 6, 7].
//
//Note:
//You may assume k is always valid, ie : 1 ≤ k ≤ input array's size for non-empty array.
//
//Follow up :
//Could you solve it in linear time ?

namespace Solution2
{
	namespace SlidingWindowMaximum
	{
		namespace logged{
			vector<int> maxSlidingWindow(vector<int>& nums, int w) {
				int len = nums.size();
				if (len == 0 || len < w) { return vector<int>(); }

				vector<int> result(len - w + 1);
				deque<int> Q;

				cout << "starting initial filling\n";
				for (int i = 0; i < w; i++)
				{
					while (!Q.empty() && nums[i] >= nums[Q.back()])
					{
						cout << "cur num nums[i] (" << nums[i] << ") is >= the back of the queue value nums[Q.back] (" << nums[Q.back()] << ")\n";
						cout << "poping back of the queue (" << Q.back() << ") with corresponding value(" << nums[Q.back()] << ") \n";
						Q.pop_back();
					}
					cout << "pushing index i (" << i << ") (corresponding value " << nums[i] << ") into the queue\n";
					Q.push_back(i);
				}
				cout << "\n\nstarting sliding the window\n";
				for (int i = w; i < len; i++)
				{
					cout << "\n\ncur i is: " << i << endl;
					cout << "setting sliding window Max at " << i - w << " to " << nums[Q.front()] << endl;
					result[i - w] = nums[Q.front()];
					while (!Q.empty() && nums[i] >= nums[Q.back()])
					{
						cout << "cur num nums[i] (" << nums[i] << ") is >= the back of the queue value nums[Q.back] (" << nums[Q.back()] << ")\n";
						cout << "poping back of the queue (" << Q.back() << ") with corresponding value(" << nums[Q.back()] << ") \n";
						Q.pop_back();
					}
					while (!Q.empty() && Q.front() <= i - w)
					{
						cout << "index val front of the queue(" << Q.front() << ") does not belong to the window, popping it out\n";
						Q.pop_front();
					}
					cout << "pushing index i (" << i << ") (corresponding value " << nums[i] << ") into the queue\n";
					Q.push_back(i);
				}

				cout << "setting sliding window Max at " << len - w << " to " << nums[Q.front()] << endl;
				result[len - w] = nums[Q.front()];
			}
		}


		vector<int> maxSlidingWindow(vector<int>& nums, int k)
		{
			int len = nums.size();
			if (len == 0 || k > len) { return vector<int>(); }

			vector<int>result(len - k + 1);
			deque<int> Q;

			for (int i = 0; i < k; i++)
			{
				while (!Q.empty() && nums[i] >= nums[Q.back()]) { Q.pop_back(); }
				Q.push_back(i);
			}

			for (int i = k; i < len; i++)
			{
				result[i - k] = nums[Q.front()];
				while (!Q.empty() && nums[i] >= nums[Q.back()]) { Q.pop_back(); }
				while (!Q.empty() && Q.front() <= i - k) { Q.pop_front(); }
				Q.push_back(i);
			}
			result[len - k] = nums[Q.front()];
			return result;
		}


		namespace Heap
		{
			vector<int> maxSlidingWindow(vector<int>& nums, int k)
			{
				int len = nums.size();
				if (len == 0 || k > len) { return vector<int>(); }

				vector<int> result(len - k + 1);
				priority_queue<pair<int, int>> q;
				for (int i = 0; i < k; i++)
				{
					q.push(make_pair(nums[i], i));
				}

				for (int i = k; i < len; i++)
				{
					result[i - k] = q.top().first;
					while (!q.empty() && q.top().second <= i - k) { q.pop(); }
					q.push(make_pair(nums[i], i));
				}
				result[len - k] = q.top().first;
				return result;
			}
		}


		void Main()
		{
			vector<int> input;

			input = { 1 };
			print(Heap::maxSlidingWindow(input, 1));
			
			input = { 1, 3, -1, -3, 5, 3, 6, 7 };
			print(Heap::maxSlidingWindow(input, 3));
		}
	}
}