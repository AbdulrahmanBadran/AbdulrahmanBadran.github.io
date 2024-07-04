#pragma once

#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <algorithm>
#include <climits>
#include <functional>
#include <iomanip>
using namespace std;

namespace myStringLib {

	vector<string> splitString(string join, string delim = "#//#") {
		vector<string>v;
		string record;
		short pos;
		while ((pos = join.find(delim)) != string::npos) {

			record = join.substr(0, pos);
			v.push_back(record);
			join.erase(0, pos + delim.length());

		}

		if (join != "")
			v.push_back(join);


		return v;

	}

	void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		cout << "\nFirst letters of this string: \n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter) 
				cout << S1[i] << endl;  

		 isFirstLetter = (S1[i] == ' ' ? true : false); 
		
		}
	}

	char  InvertLetterCase(char char1) {

		return isupper(char1) ? tolower(char1) : toupper(char1);
	
	}

	string  InvertAllStringLettersCase(string S1) {

		for (short i = 0; i < S1.length(); i++) 
			S1[i] = InvertLetterCase(S1[i]);
	 
		return S1; 
	}

	string TrimLeft(string S1) {
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ') {
				return S1.substr(i, S1.length() - i);
			}
		}
		return"";
	}

	string TrimRight(string S1)
	{ 
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return"";
	}
	
	string Trim(string S1) {

		return (TrimLeft(TrimRight(S1)));
	
	}

	string JoinString(vector<string> vString, string Delim) {
		string S1 = "";

		for (string& s : vString)
			S1 = S1 + s + Delim;

		return S1.substr(0, S1.length() - Delim.length());
	}

	string JoinString(string arrString[], short Length, string Delim) {
		
		string S1 = "";
		for (short i = 0; i < Length; i++)
			S1 = S1 + arrString[i] + Delim;
	
		return S1.substr(0, S1.length() - Delim.length()); 
	}

	string ReverseWordsInString(string S1) {

		vector<string> vString;
		string S2 = ""; 
		vString = splitString(S1, " ");
		  vector<string>::iterator iter = vString.end();

		  while (iter != vString.begin()) 
		  {   

			  --iter; 
			  S2 += *iter + " "; 
		  
		  }   
		  S2 = S2.substr(0, S2.length() - 1);

		 return S2;
	
	}

	string replaceWordInString(string str,string oldWord,string newWord) {


		vector<string>v = splitString(str, " ");

		for (string& i : v)
		{
			if (oldWord == i)
				i = newWord;
		}

		return JoinString(v, " ");

		
	}

	string RemovePunctuationsFromString(string S1) {
		
		string S2 = "";

		for (short i = 0; i < S1.length(); i++) {

			if (!ispunct(S1[i])) 
				S2 += S1[i];

		}
		return S2;
	}

	string NumberToText(long long num) {

		string arr1[] = { "zero","one","two","three","four","five","six","seven" ,"eight","nine","ten",
			"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen" };

		string arr2[] = { " ","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty" };

		string arr3[] = { "billion","million","thousand","hundred" };
		if (num == 0)
			return "";

		if (num >= 1 && num <= 19)
			return arr1[num] + " ";

		if (num >= 20 && num <= 99)
			return arr2[num / 10] + " " + NumberToText(num % 10);

		if (num >= 100 && num <= 999)
			return NumberToText(num / 100) + arr3[3] + " " + NumberToText(num % 100);

		if (num >= 1000 && num <= 999999)
			return NumberToText(num / 1000) + arr3[2] + " " + NumberToText(num % 1000);

		if (num >= 1000000 && num <= 999999999)
			return NumberToText(num / 1000000) + " " + arr3[1] + " " + NumberToText(num % 1000000);

		if (num >= 1000000000 && num <= 999999999999)
			return NumberToText(num / 1000000000) + " " + arr3[0] + " " + NumberToText(num % 1000000000);

	}

}