/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1050 String Subtraction
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: calculate s1 - s2 and be fast
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

//int main(void) {
//	int all_ascii[127] = {0};
//	string s1, s2;
//	getline(cin, s1);
//	cin >> s2;
//	for (int i = 0; i < s2.size(); i++)
//	{
//		int index = s2[i];
//		all_ascii[index] = 1;
//	}
//	for (auto it = s1.begin(); it < s1.end();) {
//		if (all_ascii[*it] == 1)
//		{
//			it = s1.erase(it);
//		}
//		else {
//			++it;
//		}
//	}
//	cout << s1 << endl;
//	return 0;
//}
int main(void) {
	string s1, s2;
	getline(cin, s1);
	cin >> s2;
	for (auto character : s2) {
		for (auto it = s1.begin(); it < s1.end();) {
			if ((*it) == character) {
				it = s1.erase(it);
			}
			else ++it;
		}
	}
	cout << s1 << endl;
	return 0;
}
 
