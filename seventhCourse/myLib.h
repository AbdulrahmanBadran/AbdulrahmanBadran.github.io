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

namespace myLib {

	enum enrandomize { smallLetters, capitalLetters, specialChar, numberDigit };

	enum enIsPrime { prime, notPrime };

	enum enYesOrNo { no, yes };


	int readNumber(string messege) {


		int num;
		cout << messege;
		cin >> num;
		return num;
	}

	short readShortNumber(string messege) {


		short num;
		cout << messege;
		cin >> num;
		return num;
	}

	float readFloatNum(string messege) {
		float num;
		cout << messege;
		cin >> num;
		return num;


	}

	double readDoubleNum(string messege) {
		double num;
		cout << messege;
		cin >> num;
		return num;


	}

	string readString(string messege) {

		string word;
		cout << messege;
		getline(cin>>ws, word);

		return word;
	}

	char readChar(string messege) {

		char letter;
		cout << messege;
		cin >> letter;
		return letter;

	}

	int reversNum(int num) {
		int num2 = 0;
		while (num > 0) {
			num2 += (num % 10);
			num2 *= 10;
			num /= 10;
		}
		return num2 /= 10;
	}

	void printDigits(int num) {

		while (num > 0) {
			cout << num % 10 << endl;
			num /= 10;

		}

	}

	bool isPalindrome(int num) {

		return num = reversNum(num);


	}

	void print(string password) {

		string word = "   ";


		int c = 1;
		for (int i = 'A'; i <= 'Z'; i++)
		{

			for (int j = 'A'; j <= 'Z'; j++)
			{
				for (int l = 'A'; l <= 'Z'; l++)
				{

					word[0] = i;
					word[1] = j;
					word[2] = l;
					cout << "trial[" << c++ << "]" << word << endl;
					if (word == password)
						return;


				}


			}


		}




	}

	string textAfterEncreption(string word, int key) {
		for (int i = 0; i < word.size(); i++)
		{
			word[i] += key;
		}

		return word;
	}

	string textAfterDecreption(string word, int key) {

		for (int i = 0; i < word.size(); i++)
		{
			word[i] -= key;
		}

		return word;


	}

	void doYouWantToDecreptTheMessege(string word, int key) {

		char status;
		do
		{
			cout << "do you want to decrept the messege(y/n): ";
			cin >> status;
			if (status == 'y') {

				cout << textAfterDecreption(word, key);
				return;
			}
			if (status == 'n') {

				cout << textAfterDecreption(word, key);
				return;
			}

		} while (status != 'n' || status != 'y');



	}

	int randomNum(int from, int to) {

		int randomNum = rand() % (to - from + 1) + from;
		return randomNum;
	}

	char RandomSth(enrandomize sth) {
		int random;
		if (sth == enrandomize::smallLetters)
		{
			random = rand() % (122 - 97 + 1) + 97;

			return (char)random;
		}

		if (sth == enrandomize::capitalLetters)
		{
			random = rand() % (90 - 65 + 1) + 65;

			return (char)random;
		}


		if (sth == enrandomize::specialChar)
		{
			random = rand() % (47 - 33 + 1) + 33;

			return (char)random;
		}

		if (sth == enrandomize::numberDigit)

		{
			random = rand() % (57 - 48 + 1) + 48;

			return (char)random;
		}

	}

	string genarateKeys() {

		string key = "";
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				key += RandomSth(enrandomize::capitalLetters);

			}
			if (i == 3)
				break;
			key += '-';
		}

		return key;
	}

	void readRandomArray(int arr[], int n) {


		for (int i = 0; i < n; i++)
		{
			arr[i] = randomNum(1, 100);
		}

	}

	void readArray(int arr[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++)
		{
			cin >> arr[i];
		}

	}

	void readStringArray(string arr[], int arrayLength) {

		for (int i = 0; i < arrayLength; i++)
		{
			arr[i] = genarateKeys();
		}


	}

	void readRandomString(string& word, int wordLength) {

		word += RandomSth(enrandomize::capitalLetters);


		for (int i = 1; i < wordLength; i++)
		{
			if (i == 21)
				word += RandomSth(enrandomize::capitalLetters);
			if (i % 2 != 0)
				word += RandomSth(enrandomize::numberDigit);
			else
				word += RandomSth(enrandomize::smallLetters);

		}

	}

	bool search(int arr[], int num, int arrayLength) {
		int c = 0;
		for (int i = 0; i != arrayLength; i++)
		{
			if (arr[i] == num)
				return 1;

		}


		return 0;
	}

	void printArray(int arr[], int arrayLength) {
		for (int i = 0; i < arrayLength; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
	}

	void printStringArray(string arr[], int arrayLength) {

		for (int i = 0; i < arrayLength; i++)
		{
			cout << arr[i] << endl;
		}

	}

	int maxNumInArray(int arr[], int arrayLength) {
		int max = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}

		return max;

	}

	int minNumInArray(int arr[], int arrayLength) {
		int min = 101;
		for (int i = 0; i < arrayLength; i++)
		{
			if (arr[i] < min)
				min = arr[i];
		}

		return min;

	}

	int sumOfArray(int arr[], int arrayLength) {

		int sum = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			sum += arr[i];
		}
		return sum;

	}

	float aveOfArray(int arr[], int arrayLength) {

		return (float)sumOfArray(arr, arrayLength) / arrayLength;



	}

	bool primeNum(int num) {

		for (int i = 2; i < num / 2; i++)
		{
			if (num % i == 0)
				return 0;
		}
		return  1;

	}

	void AddArrayElement(int arr[], int num, int& numIndex) {

		arr[numIndex] = num;
		numIndex++;
	}

	void copyDistinctArray(int arr1[], int arr2[], int arrayLength, int& arrayLength2) {
		for (int i = 0; i < arrayLength; i++)
		{
			if (!search(arr2, arr1[i], arrayLength))
				AddArrayElement(arr2, arr1[i], arrayLength2);

		}
	}

	void sumOf2Array(int arr1[], int arr2[], int arr3[], int arrayLength) {

		for (int i = 0; i < arrayLength; i++)
		{
			arr3[i] = arr1[i] + arr2[i];
		}


	}

	void arrayShufling(int arr[], int arr2[], int arrayLength) {
		int temp;
		int index;

		for (int i = 0; i < arrayLength; i++)
		{
			/*for (int j = 0; true; j++)
			{
				if (search(arr2, index, arrayLength))
					index = randomNum(0, arrayLength-1);

				else
					break;
			}*/


			//arr2[i] = index;
			index = randomNum(0, arrayLength - 1);
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;

		}
		cout << endl;
	}

	int indexFounder(int arr[], int num, int arrayLength) {



		for (int i = 0; i < arrayLength; i++)
		{
			if (arr[i] == num)
				return i;
		}

		return -1;



	}

	void readArrayFromUser(int arr[], int& i) {
		bool addNum = 1;


		do
		{
			AddArrayElement(arr, readNumber("enter an element to the array:"), i);
			cout << "do you want to add more element [0] NO  [1] YES:";
			cin >> addNum;

		} while (addNum);


	}

	bool isPalindromeArray(int arr[], int arrayLength) {
		for (int i = 0, j = arrayLength - 1; i < arrayLength / 2; i++, j--)
		{
			if (arr[i] != arr[j])
				return false;
		}
		return true;


	}

	int numberOfOddNumberInArray(int arr[], int arrayLength) {
		int c = 0;
		for (int i = 0; i < arrayLength; i++)
		{
			if (arr[i] > 0)
				c++;
		}

		return c;
	}

	float myAbs(float num) {
		if (num < 0)
			return num * -1;
		return num;



	}

	float getFraction(float num) {

		return num - (int)num;
	}

	int myRound(float num) {

		int IntPart;
		IntPart = (int)num;
		float fractionPart = getFraction(num);
		if (myAbs(fractionPart) >= 0.5)
			if (num >= 0)
				return ++num;
			else
				--num;

		return num;
	}

	int myFloor(float num) {
		if (num >= 0)
			return num;

		return --num;


	}

	int myCeil(float num) {
		if (myAbs(getFraction(num)) > 0)
			if (num >= 0)
				return ++num;


		return num;


	}

	float mySqrt(float num) {

		return pow(num, 0.5);
	}

	bool digitsChecker(int num1, int num2) {
		int digit;
		for (; num1 > 0;)
		{
			int num2Digit = num2;

			digit = num1 % 10;
			num1 /= 10;
			for (; num2Digit > 0; )
			{
				if (num2Digit % 10 == digit)
					return 0;
				num2Digit /= 10;
			}


		}
		return 1;

	}

	void printPrimeNumbers() {

		int n = readNumber("enter the number of prime number you want to print");

		int primeNumber = 2, primeNumber2 = 0;
		for (int i = 0; i < n; )
		{
			if (primeNum(primeNumber)) {
				if (digitsChecker(primeNumber, primeNumber2))
				{
					cout << primeNumber << " ";

					primeNumber2 = primeNumber;
					if (primeNumber > 10)
						primeNumber += 7;
					i++;
				}

			}

			primeNumber++;
		}



	}

}
