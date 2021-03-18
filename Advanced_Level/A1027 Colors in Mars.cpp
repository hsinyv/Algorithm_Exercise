/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1027 Colors in Mars
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: Radix transform
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

vector<string> value2digit = { "0","1", "2", "3", "4", "5", "6", "7", "8", \
							   "9", "A", "B", "C" };

string Decimal2AnyRadix(string ini_number, int radix = 13) {
	int number = stoi(ini_number);
	string result;
	while (number >= radix) {
		int remain = number % radix;
		number = number / radix;
		result = value2digit[remain] + result;
	}
	result = value2digit[number] + result;
	if (result.size() < 2) result = "0" + result;
	return result;
}

int main(void) {
	string red_dec, green_dec, blue_dec;
	cin >> red_dec >> green_dec >> blue_dec;
	string red_mars = Decimal2AnyRadix(red_dec);
	string green_mars = Decimal2AnyRadix(green_dec);
	string blue_mars = Decimal2AnyRadix(blue_dec);
	cout << "#" << red_mars << green_mars << blue_mars << endl;
	return 0;
}
 
