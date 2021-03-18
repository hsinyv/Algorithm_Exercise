/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1069 The Black Hole of Numbers
*  Date: 2021/03/13
***********************************************/
/***********************************************
* Core Mission: requirement is simple, just follow instruction
*				input number may not be 4 digits
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

int main(void) {
	string number;	
	cin >> number;
	while (number.size() < 4) {
		number = "0" + number;
	}
	if (number == "6174") {
		cout << "7641 - 1467 = 6174\n";
	}
	while (number != "6174") {
		string inc_number = number;
		string dec_number = number;
		sort(inc_number.begin(), inc_number.end(), [](char a, char b) {return a > b; });
		sort(dec_number.begin(), dec_number.end());
		number = to_string(stoi(inc_number) - stoi(dec_number));
		while (number.size() < 4) {
			number = "0" + number;
		}
		cout << inc_number << " - " << dec_number << " = " << number << endl;
		if (number == "0000") break;
	}
	
	
	return 0;
}
 
