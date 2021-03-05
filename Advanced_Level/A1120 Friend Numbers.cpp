/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1120 Friend Numbers
*  Date: 2021/03/03
***********************************************/
/***********************************************
* Core Mission: calculate sum of digits of every number and calculate appearence
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

int DigitSum(string s) {
	int friend_id = 0;
	for (auto digit : s) {
		friend_id += (digit - '0');
	}
	return friend_id;
}

int main(void) {
	int n; cin >> n;
	vector<int> all_friend_id;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		int friend_id = DigitSum(s);
		vector<int>::iterator it = find(all_friend_id.begin(), all_friend_id.end(), friend_id);
		if ( it == all_friend_id.end()) {
			all_friend_id.push_back(friend_id);
		}
	}
	sort(all_friend_id.begin(), all_friend_id.end());
	cout << all_friend_id.size() << endl;
	for (int i = 0; i < all_friend_id.size(); i++)
	{
		cout << all_friend_id[i];
		if (i < all_friend_id.size() - 1) cout << " ";
		else cout << endl;
	}
	
	return 0;
}
 
