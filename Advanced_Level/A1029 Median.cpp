/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.1029 Median
*  Date: 2021/03/12
***********************************************/
/***********************************************
* Core Mission: find the median, pay attention to index if seq.size() is even
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

typedef long long ll;

int main(void) {
	int n; cin >> n;
	vector<ll> seq;
	for (int i = 0; i < n; i++)
	{
		ll t;	cin >> t;
		seq.push_back(t);
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll t;	cin >> t;
		seq.push_back(t);
	}
	sort(seq.begin(), seq.end());
	int media_index = (seq.size() % 2 == 0) ? ((seq.size() / 2) - 1) : (seq.size() / 2);
	cout << seq[media_index] << endl;

	return 0;
}
 
