/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1084 Broken Keyboard
*  Date: 2021/03/03
***********************************************/
/***********************************************
* Core Mission: compare two string and print characters who appears in original string but the 
*	typed out string
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
#include <unordered_set>
using namespace std;

int main(void) {
	string original_s, typed_s;
	//unordered_set<char> broken_key;
	vector<char> broken_key;
	cin >> original_s >> typed_s;
	transform(original_s.begin(), original_s.end(), original_s.begin(), ::toupper);
	transform(typed_s.begin(), typed_s.end(), typed_s.begin(), ::toupper);
	for (int i = 0, j = 0; i < original_s.size();) {
		if (original_s[i] == typed_s[j]) {
			++i; ++j;
		}
		else {
			//broken_key.insert(original_s[i]);
			if (find(broken_key.begin(), broken_key.end(), original_s[i]) == broken_key.end()) {
				broken_key.push_back(original_s[i]);
			}
			++i;
		}
	}

	for (auto i : broken_key)
		cout << i;
	cout << endl;
	return 0;
}
 
