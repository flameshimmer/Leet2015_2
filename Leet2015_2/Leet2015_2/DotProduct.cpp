#include "stdafx.h"

//Given two sparse Vectors, compute the Dot Product.
//Input Format : The first line will contain two numbers(k and n), which are the number of entries for the two vectors respectively.
//The next k lines are the entries for the first vector, of the form : x y
//where x is the position and y is the value at that position in the vector.
//The n lines are the entries of the second vector.
//Any entries not specified indicate zero at that position.
//The two vectors will always be of the same length
//
//Example input :
//3 3
//1 4
//4 2
//5 3
//1 7
//2 6
//5 1
//
//Sample Answer : Dot Product = 4 * 7 + 3 * 1 = 31 (only print 31)


namespace Solution2
{
	namespace DotProduct
	{
		
		int findDotProduct(vector<pair<int, int>>& v1, vector<pair<int, int>>& v2)
		{
			int len1 = v1.size();
			int len2 = v2.size();
			int len = min(len1, len2);

			int i1 = 0;
			int i2 = 0;
			int result = 0;
			while (i1 < len && i2 < len)
			{
				if (v1[i1].first == v2[i2].first) { result += v1[i1].second * v2[i2].second; i1++; i2++; }
				else if (v1[i1].first < v2[i2].first) { i1++; }
				else { i2++; }
			}
			return result;
		}

		void Main()
		{
			vector<pair<int, int>> v1; 
			vector<pair<int, int>> v2;
			
			v1 = { { 1, 4 }, { 4, 2 }, { 5, 3 } };
			v2 = { { 1, 7 }, { 2, 6 }, { 5, 1 } };			
			print(findDotProduct(v1, v2));

			v1 = {};
			v2 = { { 1, 7 }, { 2, 6 }, { 5, 1 } };
			print(findDotProduct(v1, v2));

			v1 = { { 1, 4 }, { 4, 2 }, { 5, 3 } };
			v2 = {};
			print(findDotProduct(v1, v2));

			v1 = {};
			v2 = {};
			print(findDotProduct(v1, v2));
		}
	}
}
