#include "stdafx.h"

//Validate if a given string is numeric.
//
//Some examples :
//"0" = > true
//" 0.1 " = > true
//"abc" = > false
//"1 a" = > false
//"2e10" = > true
//Note: It is intended for the problem statement to be ambiguous.
//You should gather all requirements up front before implementing one.

namespace Solution2
{
    namespace ValidNumber
    {
     
		bool isNumber(string s) {
			int len = s.size();
			if (len == 0) { return false; }

			int i = 0;
			while (i < len && s[i] == ' ') { i++; }

			if (s[i] == '+' || s[i] == '-') { i++; }

			int cDot = 0; int cDigit = 0;
			while (isdigit(s[i]) || s[i] == '.') { s[i] == '.' ? cDot++ : cDigit++; i++; }
			if (cDot > 1 || cDigit < 1) { return false; }

			if (s[i] == 'e' || s[i] == 'E')
			{
				i++;
				if (s[i] == '+' || s[i] == '-') { i++; }
				cDot = 0; cDigit = 0;
				while (isdigit(s[i]) || s[i] == '.') { s[i] == '.' ? cDot++ : cDigit++; i++; }
				if (cDot > 0 || cDigit < 1) { return false; }
			}
			while (i < len && s[i] == ' '){ i++; }
			return i == len;
		}


		namespace FiniteStateMachine
		{
			bool isNumber(string s)
			{
				enum InputType
				{
					Invalid,
					Space,
					Sign,
					Digit,
					Dot,
					E
				};

				enum State
				{
					EmptyOrSpace, // 0
					AfterSign, // 1
					AfterDot, // 2
					AfterDigit, // 3
					AfterDigitDot, // 4
					DigitAfterDot, // 5
					AfterE, // 6
					SignAfterE, // 7
					DigitAfterE, // 8
					EndSpace // 9
				};

				vector<vector<int>> table(10, vector<int>(6, -1));

				table[EmptyOrSpace][Space] = EmptyOrSpace;
				table[EmptyOrSpace][Sign] = AfterSign;
				table[EmptyOrSpace][Digit] = AfterDigit;
				table[EmptyOrSpace][Dot] = AfterDot;

				table[AfterSign][Dot] = AfterDot;
				table[AfterSign][Digit] = AfterDigit;

				table[AfterDigit][Digit] = AfterDigit;
				table[AfterDigit][Dot] = AfterDigitDot;
				table[AfterDigit][E] = AfterE;
				table[AfterDigit][Space] = EndSpace;

				table[AfterDigitDot][Digit] = DigitAfterDot;
				table[AfterDigitDot][Space] = EndSpace;
				table[AfterDigitDot][E] = AfterE;

				table[AfterDot][Digit] = DigitAfterDot;

				table[DigitAfterDot][Digit] = DigitAfterDot;
				table[DigitAfterDot][E] = AfterE;
				table[DigitAfterDot][Space] = EndSpace;

				table[AfterE][Sign] = SignAfterE;
				table[AfterE][Digit] = DigitAfterE;

				table[SignAfterE][Digit] = DigitAfterE;

				table[DigitAfterE][Digit] = DigitAfterE;
				table[DigitAfterE][Space] = EndSpace;

				table[EndSpace][Space] = EndSpace;

				int state = EmptyOrSpace;
				for (char c : s)
				{
					int input = Invalid;
					if (c == '+' || c == '-') { input = Sign; }
					else if (c == ' ') { input = Space; }
					else if (c == 'E' || c == 'e') { input = E; }
					else if (c == '.') { input = Dot; }
					else if (c - '0' >= 0 && c - '0' <= 9) { input = Digit; }

					state = table[state][input];
					if (state == -1) { return false; }
				}
				return state == AfterDigit || state == DigitAfterDot || state == DigitAfterE || state == EndSpace || state == AfterDigitDot;
			}
		}
     
        void Main()
        {
			print(isNumber("46.e3"));
			print(isNumber("3."));
			print(isNumber("e9"));
			print(isNumber("."));
        }
    }
}
