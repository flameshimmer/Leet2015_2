#include "stdafx.h"

//Compare two version numbers version1 and version2.
//If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
//
//You may assume that the version strings are non - empty and contain only digits and the.character.
//The.character does not represent a decimal point and is used to separate number sequences.
//For instance, 2.5 is not "two and a half" or "half way to version three", 
//it is the fifth second - level revision of the second first - level revision.
//
//Here is an example of version numbers ordering :
//
//0.1 < 1.1 < 1.2 < 13.37

namespace Solution2
{
    namespace CompareVersionNumbers
    {
		int compareVersion(string version1, string version2) 
		{
			int len1 = version1.size();
			int len2 = version2.size();
			int i1 = 0;
			int i2 = 0;

			while (i1 < len1 || i2 < len2)
			{
				int v1 = 0;
				while (i1 < len1 && version1[i1] != '.')
				{
					v1 = v1 * 10 + version1[i1] - '0';
					i1++;
				}
				while (i1 < len1 && version1[i1] == '.') { i1++; }

				int v2 = 0;
				while (i2 < len2 && version2[i2] != '.')
				{
					v2 = v2 * 10 + version2[i2] - '0';
					i2++;
				}
				while (i2 < len2 && version1[i2] == '.') { i2++; }

				if (v1 > v2) { return 1; }
				if (v1 < v2) { return -1; }
			}
			return 0;
		}
     
        void Main()
        {
			print(compareVersion("0", "1"));
        }
    }
}
