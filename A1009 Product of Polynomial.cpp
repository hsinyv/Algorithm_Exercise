/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1009 Product of Polynomial
*  Date: 2021/03/07
***********************************************/
/***********************************************
* Core Mission: easy
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
	map<int, double, greater<int>> polynomials, result_polynomials;
	int terms_num;
	cin >> terms_num;
	for (int i = 0; i < terms_num; i++)
	{
		int exponent; double coefficient;
		cin >> exponent >> coefficient;
		polynomials[exponent] = coefficient;
	}
	cin >> terms_num;
	for (int i = 0; i < terms_num; i++)
	{
		int exponent; double coefficient;
		cin >> exponent >> coefficient;
		for (auto term : polynomials) {
			int result_exponent = exponent + term.first; 
			double result_coefficient = coefficient * term.second;
			map<int, double>::iterator it = result_polynomials.find(result_exponent);
			if (it != result_polynomials.end()) {
				(*it).second += result_coefficient;
			}
			else {
				result_polynomials[result_exponent] = result_coefficient;
			}
		}
	}
	for (auto it = result_polynomials.begin(); it != result_polynomials.end();) {
		if ((*it).second == 0) {
			it = result_polynomials.erase(it);
		}
		else {
			++it;
		}
	}
	cout << result_polynomials.size();
	if (result_polynomials.size() > 0) {
		cout << " ";
	}
	int cnt = 0;
	for (auto it : result_polynomials) {
		cout << it.first << " ";
		cout << fixed << setprecision(1) << it.second;
		if (cnt < result_polynomials.size() - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
		++cnt;
	}


	return 0;
}
 
