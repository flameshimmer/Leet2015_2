#include "stdafx.h"

//Design an algorithm to encode a list of strings to a string.The encoded string is then sent over the network and is decoded back to the original list of strings.
//
//Machine 1 (sender)has the function :
//
//string encode(vector<string> strs) {
//	// ... your code
//	return encoded_string;
//}
//Machine 2 (receiver)has the function :
//vector<string> decode(string s) {
//	//... your code
//	return strs;
//}
//So Machine 1 does :
//
//string encoded_string = encode(strs);
//and Machine 2 does:
//
//vector<string> strs2 = decode(encoded_string);
//strs2 in Machine 2 should be the same as strs in Machine 1.
//
//Implement the encode and decode methods.
//
//Note:
//The string may contain any possible characters out of 256 valid ascii characters.Your algorithm should be generalized enough to work on any possible characters.
//Do not use class member / global / static variables to store states.Your encode and decode algorithms should be stateless.
//Do not rely on any library method such as eval or serialize methods.You should implement your own encode / decode algorithm.

namespace Solution2
{
	namespace EncodeAndDecodeStrings
	{
		class Codec {

		public:
			// Encodes a list of strings to a single string.
			string encode(vector<string>& strs) {
				string result;
				for (string s : strs)
				{
					result += to_string(s.size()) + "@" + s;
				}
				return result;
			}

			// Decodes a single string to a list of strings.
			vector<string> decode(string s) {
				vector<string> result;
				int len = s.size(); if (len == 0) { return result; }

				int start = 0;
				while (start < len)
				{
					int end = start + 1;
					while (end < len && s[end] != '@') { end++; }
					end--;

					int count = 0; 
					while (start <= end) { count = count * 10 + (s[start] - '0'); start++; }
					start++;

					result.push_back(s.substr(start, count));
					start += count;
				}
				return result;
			}
		};

		// Your Codec object will be instantiated and called as such:
		// Codec codec;
		// codec.decode(codec.encode(strs));


		void Main()
		{
			Codec codec;
			vector<string> strs;
			strs = { "" };
			print(codec.decode(codec.encode(strs)));

			strs = { "abc", "d", "ef", "ghf" };
			print(codec.decode(codec.encode(strs)));
		}
	}
}
