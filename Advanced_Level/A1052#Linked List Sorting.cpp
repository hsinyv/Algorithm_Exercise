/***********************************************
*  Program Ability Test Advanced Level Practice
*  No.A1052 Linked List Sorting
*  Date: 2021/03/16
***********************************************/
/***********************************************
* Core Mission: 
* Point:  Not all the node given is in one list and may be the list is empty
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

bool ListCmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main(void) {
	int num_nodes, head_addr;
	cin >> num_nodes >> head_addr;
	int addr2data[100005];
	int addr2next[100005];
	for (int i = 0; i < num_nodes; i++)
	{
		int addr;
		cin >> addr;
		cin >> addr2data[addr] >> addr2next[addr];
	}
	vector<pair<int, int>> list;
	int next = head_addr;
	while (next != -1) {
		list.push_back(make_pair(next,addr2data[next]));
		next = addr2next[next];
	}
	sort(list.begin(), list.end(), ListCmp);
	if (list.size() > 0) {
		printf("%d %05d\n", list.size(), list[0].first);
		int i = 0;
		for (i = 0; i < list.size() - 1; i++)
		{
			printf("%05d %d %05d\n", list[i].first, list[i].second, list[i + 1].first);
		}
		printf("%05d %d -1\n", list[i].first, list[i].second);
	}
	else {
		printf("0 -1\n");
	}
	
	return 0;
}
 
