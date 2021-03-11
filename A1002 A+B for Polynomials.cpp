/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1002 A+B for Polynomials
*  Date: 2021/03/07
***********************************************/
/***********************************************
* Core Mission: pay attention to output format
*	"there must be NO extra space at the end of each line."
*	if the result is 0, then there should be no extra space after number of non_zero terms.
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
	map<int, double, greater<int>> polynomials;
	for (int i = 0; i < 2; i++)
	{
		int terms_num;
		cin >> terms_num;
		for (int i = 0; i < terms_num; i++)
		{
			int exponent; double coefficient;
			cin >> exponent >> coefficient;
			map<int, double>::iterator it = polynomials.find(exponent);
			if (it != polynomials.end()) {
				(*it).second += coefficient;
			}
			else {
				polynomials[exponent] = coefficient;
			}
		}
	}

	for (auto it = polynomials.begin(); it != polynomials.end(); ) {
		if ((*it).second == 0) {
			it = polynomials.erase(it);
		}
		else {
			++it;
		}
	}

	cout << polynomials.size();
	if (polynomials.size() > 0) {
		cout << " ";
	}
	int cnt = 0;
	for (auto term : polynomials) {
		cout << term.first << " ";
		cout << fixed << setprecision(1) << term.second;
		if (cnt < polynomials.size() - 1) {
			cout << " ";
		}
		++cnt;
	}
	cout << endl;
	return 0;
}
 
