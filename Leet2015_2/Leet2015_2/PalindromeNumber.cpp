#include "stdafx.h"

//Determine whether an integer is a palindrome.Do this without extra space.
//
//click to show spoilers.
//
//Some hints :
//Could negative integers be palindromes ? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer.However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.How would you handle such case ?
//
//There is a more generic way of solving this problem.

namespace Solution2
{
    namespace PalindromeNumber
    {     
		bool isPalindrome(int x) {
			if (x < 0) { return false; }
			long long div = 1;
			int n = x;
			while (n)
			{
				div *= 10;
				n /= 10;
			}
			div /= 10;

			while (x)
			{
				int lastDigit = x % 10;
				int firstDigit = x / div;
				if (lastDigit != firstDigit) { return false; }
				x = (x % div) / 10;
				div /= 100;
			}
			return true;
		}
     
     
        void Main()
        {
			print(isPalindrome(1000000001));
			print(isPalindrome(121));
			print(isPalindrome(-101));
        }
    }
}
