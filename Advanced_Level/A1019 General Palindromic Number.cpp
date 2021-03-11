/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1019 General Palindromic Number
*  Date: 2021/03/11
***********************************************/
/***********************************************
* Core Mission: 
* Point:  
***********************************************/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef vector<string> NumberString;

NumberString Decimal2AnyRadix(string ini_number, int radix) {
	int number = stoi(ini_number);
	NumberString result;
	while (number >= radix) {
		int remain = number % radix;
		number = number / radix;
		result.push_back(to_string(remain));
	}
	result.push_back(to_string(number));
	return result;
	//reverse order
}

bool IsPalindromic(NumberString a, NumberString b) {
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(void) {
	string ini_number; int radix;
	cin >> ini_number >> radix;
	NumberString backward_number = Decimal2AnyRadix(ini_number, radix);
	NumberString forward_number = backward_number;
	reverse(forward_number.begin(), forward_number.end());
	if (IsPalindromic(forward_number, backward_number)) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	for (int i = 0; i < forward_number.size(); i++)
	{
		cout << forward_number[i];
		if (i < forward_number.size() - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}

	return 0;
}
 
