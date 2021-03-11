/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1015 Reversible Primes
*  Date: 2021/0
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

bool IsPrime(int n) {
	if (n <= 1)return false;
	for (int i = 2; i < n/2; i++)
	{
		if (n % i == 0)return false;
	}
	return true;
}

string Decimal2AnyRadix(string ini_number, int radix) {
	//radix <= 10
	int number = stoi(ini_number);
	string result;
	while (number >= radix) {
		int remain = number % radix;
		number = number / radix;
		result = to_string(remain) + result;
	}
	result = to_string(number) + result;
	return result;
}

string AnyRadix2Decimal(string ini_number, int radix) {
	reverse(ini_number.begin(), ini_number.end());
	int decimal = 0;
	int weight = 1;
	for (auto it : ini_number) {
		decimal = decimal + (it - '0') * weight;
		weight *= radix;
	}
	return to_string(decimal);
}

int main(void) {
	int number, radix;
	cin >> number;
	while (number > 0) {
		cin >> radix;
		string forward_decimal_number = to_string(number);
		string backward_any_radix_number = forward_decimal_number;
		if (radix != 10) {
			backward_any_radix_number = Decimal2AnyRadix(forward_decimal_number, radix);
		}	
		reverse(backward_any_radix_number.begin(), backward_any_radix_number.end());
		string backward_decimal_number = backward_any_radix_number;
		if (radix != 10) {
			backward_decimal_number = AnyRadix2Decimal(backward_any_radix_number, radix);
		}
		if (IsPrime(stoi(forward_decimal_number)) && IsPrime(stoi(backward_decimal_number))) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		cin >> number;
	}

	return 0;
}
 
