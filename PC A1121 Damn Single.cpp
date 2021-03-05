/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1121 Damn Single
*  Date: 2021/03/03
***********************************************/
/***********************************************
* Core Mission: 
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
	int marriage_records_num; scanf("%d", &marriage_records_num);
	map<string, string> marriage_records;
	for (int i = 0; i < marriage_records_num; i++)
	{
		string couple_A, couple_B;
		couple_A.resize(5); couple_B.resize(5);
		scanf("%s %s", &couple_A[0], &couple_B[0]);
		marriage_records[couple_A] = couple_B;
		marriage_records[couple_B] = couple_A;
	}
	int guests_num; scanf("%d", &guests_num);
	vector<string> lonely_guests;
	vector<string> presented_married_guests;
	for (int i = 0; i < guests_num; i++)
	{
		string guest; guest.resize(5);
		scanf("%s", &guest[0]);
		map<string, string>::iterator it = marriage_records.find(guest);
		if (it == marriage_records.end()) {
			lonely_guests.push_back(guest);
		}
		else {
			presented_married_guests.push_back(guest);
		}
		}
	//deal with presented and married guests
	for (auto guest_it = presented_married_guests.begin(); \
		guest_it < presented_married_guests.end(); ++guest_it) {
		vector<string>::iterator it = find(guest_it + 1, \
			presented_married_guests.end(), marriage_records[*guest_it]);
		if (it == presented_married_guests.end()) {
			lonely_guests.push_back(*guest_it);
		}
		else {
			presented_married_guests.erase(it);
		}
	}
	sort(lonely_guests.begin(), lonely_guests.end());
	printf("%d\n", lonely_guests.size());
	for (int i = 0; i < lonely_guests.size(); i++)
	{
		printf("%s", (lonely_guests[i]).c_str());
		if (i < lonely_guests.size() - 1) printf(" ");
		else printf("\n");
	}
	return 0;
}
 
