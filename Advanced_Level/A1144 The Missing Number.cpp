/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1144 The Missing Number
*  Date: 2021/03/04
***********************************************/
/***********************************************
* Core Mission: find the smallest missing positive integer
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
#include <set>
using namespace std;

int main(void) {
	int n; 
	cin >> n;
	set<int> all_integer;
	for (int i = 0; i < n; i++)
	{
		int t; cin >> t;
		if (t > 0) all_integer.insert(t);
	}
	//int cnt = *(all_integer.begin());
	int cnt = 1;
	for (auto i : all_integer) {
		if (cnt != i) {
			break;
		}
		++cnt;
	}
	//deal with the cases that missing number between the sequence or in the last position 
	cout << cnt << endl;
	return 0;
}
 
