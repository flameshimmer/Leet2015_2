#include "stdafx.h"

//There are a total of n courses you have to take, labeled from 0 to n - 1.
//
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair : [0, 1]
//
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses ?
//
//For example :
//
//2, [[1, 0]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0. So it is possible.
//
//2, [[1, 0], [0, 1]]
//There are a total of 2 courses to take.To take course 1 you should have finished course 0, 
//and to take course 0 you should also have finished course 1. So it is impossible.
//
//Note:
//The input prerequisites is a graph represented by a list of edges, not adjacency matrices.Read more about how a graph is represented.

namespace Solution2
{
    namespace CourseSchedule
    {     
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
		{
			vector<int>inDegree(numCourses, 0);
			vector<vector<int>> children(numCourses, vector<int>(0));
			int len = prerequisites.size();

			for (pair<int, int> pre : prerequisites)
			{
				inDegree[pre.first]++;
				children[pre.second].push_back(pre.first);
			}

			queue<int> q;
			for (int i = 0; i < numCourses; i++)
			{
				if (inDegree[i] == 0) { q.push(i); }
			}

			int processed = 0;
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();
				processed++;
				for (int i : children[cur])
				{
					inDegree[i]--;
					if (inDegree[i] == 0) { q.push(i); }
				}
			}
			return processed == numCourses;
		}
     
        void Main()
        {
         
        }
    }
}
