/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1092 To Buy or Not to Buy
*  Date: 2021/03/03
***********************************************/
/***********************************************
* Core Mission: character match and count
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
	string selling_beads_string, needed_beads_string;
	cin >> selling_beads_string >> needed_beads_string;
	bool to_buy_flag = true; int missing_beads_num = 0;
	for (auto bead : needed_beads_string) {
		string::iterator it = find(selling_beads_string.begin(), selling_beads_string.end(), bead);
		if (it == selling_beads_string.end()) {
			to_buy_flag = false;
			++missing_beads_num;
		}
		else {
			*it = '#';
		}
	}
	if (to_buy_flag) {
		cout << "Yes " << selling_beads_string.size() - needed_beads_string.size() << endl;
	}
	else {
		cout << "No " << missing_beads_num << endl;
	}
	return 0;
}
 
