/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1041 Be Unique
*  Date: 2021/0
***********************************************/
/***********************************************
* Core Mission: find the first unique number and be fast
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
	int n; scanf("%d", &n);
	vector<int> number_candidates;
	vector<int> repeated_number;
	for (int i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		vector<int>::iterator it_1 = find(repeated_number.begin(), repeated_number.end(), t);
		if (it_1 == repeated_number.end()) {
			vector<int>::iterator it_2 = find(number_candidates.begin(), number_candidates.end(), t);
			if (it_2 == number_candidates.end()) {
				number_candidates.push_back(t);
			}
			else {
				number_candidates.erase(it_2);
				repeated_number.push_back(t);
			}
		}		
	}
	if (number_candidates.size() == 0) {
		printf("None\n");
	}
	else {
		printf("%d\n", number_candidates[0]);
	}
	return 0;
}
 
