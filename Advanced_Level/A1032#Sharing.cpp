/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1032 Sharing
*  Date: 2021/03/14 TimeOut 2021/3/18 AC
***********************************************/
/***********************************************
* Core Mission: 
* Point:  the string may be empty
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

vector<int> ReproduceVocabulary(int *addr2next, int head_addr) {
	vector<int> strlist;
	int next = head_addr;
	while (next != -1) {
		strlist.push_back(next);
		next = addr2next[next];
	}
	return strlist;
}

void FindSharingPos(vector<int> s1, vector<int> s2) {
	int loop_lim = s1.size() < s2.size() ? s1.size() : s2.size();
	if (loop_lim == 0) {
		printf("-1\n");
		return;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	bool not_found = true;
	for (int i = 0; i < loop_lim; i++)
	{
		if (s1[i] != s2[i]) {
			if (i > 0) {
				printf("%05d\n", s1[i - 1]);
				not_found = false;
			}
			else {
				printf("-1\n");
				return;
			}
			break;
		}
	}
	if (not_found) {
		printf("%05d\n", s1[loop_lim - 1]);
	}
	
	return;
}

int main(void) {
	//char addr2data[100005];
	int addr2next[100005];
	int a_head_addr, b_head_addr, num_char;
	cin >> a_head_addr >> b_head_addr >> num_char;
	for (int i = 0; i < num_char; i++)
	{
		int addr; char c;
		cin >> addr;
		//cin >> addr2data[addr] >> addr2next[addr];
		cin >> c >> addr2next[addr];
	}
	vector<int> str1 = ReproduceVocabulary(addr2next, a_head_addr);
	vector<int> str2 = ReproduceVocabulary(addr2next, b_head_addr);
	FindSharingPos(str1, str2);
	return 0;
}
 
