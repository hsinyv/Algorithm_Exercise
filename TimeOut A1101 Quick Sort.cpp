/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1101 Quick Sort
*  https://pintia.cn/problem-sets/994805342720868352/problems/994805366343188480
*  Date: 2021/02/25
***********************************************/
/***********************************************
* Core Mission: Find the pivot candidates whose left-side elements is not bigger and
*	right-side elements is not smaller
* Log:  Most of test cases are time out, so the algorithm I take now is low efficient.
*	But I can not find a better solution now.[02/25]
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

bool IsPivot(vector<int> const ini_seq, int const index, vector<bool> const seq_status) {
	//left-side
	for (int i = index; i >= 0; i--)
	{
		if (ini_seq[i] > ini_seq[index]) return false;
		if (seq_status[i] && ini_seq[i] <= ini_seq[index]) break;
	}

	//right-side
	for (int i = index; i < ini_seq.size(); i++)
	{
		if (ini_seq[i] < ini_seq[index]) return false;
	}

	
	//can be a pivot
	return true;
}

int main(void) {
	int num; cin >> num;
	vector<int> ini_seq;
	ini_seq.resize(num);
	vector<bool> seq_status(num, false);
	for (size_t i = 0; i < num; i++)
	{
		cin >> ini_seq[i];
	}
	vector<int> pivot_candidates;
	for (int i = 0; i < ini_seq.size(); ++i) {
		if (IsPivot(ini_seq, i, seq_status)) {
			pivot_candidates.push_back(ini_seq[i]);
			seq_status[i] = true;
		}
	}
	cout << pivot_candidates.size() << endl;
	for (int i = 0; i < pivot_candidates.size(); ++i) {
		cout << pivot_candidates[i];
		if (i < pivot_candidates.size() - 1) cout << " ";
	}
	cout << endl;
	return 0;
}
 